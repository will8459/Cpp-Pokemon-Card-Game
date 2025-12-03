#include "Zoo.h"
#include "KNNDouble.h"
#include "KNNString.h"
#include <map>

// Initialisation de la variable statique
int Zoo::MAX_CAPACITY = 10;

Zoo::Zoo() : name("MyZoo") {}

Zoo::Zoo(string _name) : name(_name) {}

// Constructeur de copie (Deep Copy)
Zoo::Zoo(const Zoo& other) : name(other.name) {
    // On doit copier chaque animal individuellement pour éviter le partage de pointeurs
    for (Animal* animal : other.animals) {
        if (Mammal* m = dynamic_cast<Mammal*>(animal)) {
            // Utilise le constructeur de copie de Mammal
            animals.push_back(new Mammal(*m)); 
        } else if (Bird* b = dynamic_cast<Bird*>(animal)) {
            animals.push_back(new Bird(*b));
        } else if (Reptile* r = dynamic_cast<Reptile*>(animal)) {
            animals.push_back(new Reptile(*r));
        } else {
            // Animal générique
            animals.push_back(new Animal(*animal));
        }
    }
}

// Destructeur
Zoo::~Zoo() {
    // Nettoyage de la mémoire pour chaque animal
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

string Zoo::getName() const { return name; }
void Zoo::setName(const string& _name) { name = _name; }
void Zoo::setMaxCapacity(int _cap) { MAX_CAPACITY = _cap; }

void Zoo::listAnimals() const {
    cout << "Listing animals in " << name << ":" << endl;
    cout << "[" << endl;
    for (const auto& animal : animals) {
        animal->printInfo();
        cout << endl;
    }
    cout << "]" << endl;
}

void Zoo::addAnimal(Animal* _animal) {
    if ((int)animals.size() >= MAX_CAPACITY) {
        cout << "Zoo is full!" << endl;
        delete _animal;
        return;
    }

    // On utilise lower_bound pour insertion triée
    // On cherche la première position où l'animal actuel n'est pas "plus petit" (alphabétiquement) que le nouvel animal.
    auto it = lower_bound(animals.begin(), animals.end(), _animal, 
        [](Animal* a, Animal* b) {
            return a->getName() < b->getName();
        });

    // Vérification de doublon strict
    if (it != animals.end() && (*it)->getName() == _animal->getName()) {
        cout << "Error: Animal " << _animal->getName() << " already exists." << endl;
        delete _animal;
        return;
    }

    animals.insert(it, _animal);
}

int Zoo::searchAnimalByName(string _name) {
    // Comme le vecteur est trié, on peut utiliser une recherche dichotomique.
    
    // On crée un animal temporaire juste pour la comparaison
    Animal temp; 
    temp.setName(_name);

    auto it = lower_bound(animals.begin(), animals.end(), &temp, 
        [](Animal* a, Animal* b) {
            return a->getName() < b->getName();
        });

    // lower_bound renvoie un itérateur >= à la valeur cherchée.
    // Il faut vérifier si on est pas à la fin ET si c'est bien égal.
    if (it != animals.end() && (*it)->getName() == _name) {
        return distance(animals.begin(), it); // Renvoie l'indice
    }
    
    return -1; // Non trouvé
}

void Zoo::removeAnimalByName(string _name) {
    int index = searchAnimalByName(_name);
    if (index != -1) {
        // supprimer le pointeur ET l'objet en mémoire
        delete animals[index];
        animals.erase(animals.begin() + index);
    } else {
        cout << "Animal " << _name << " does not exist in the Zoo." << endl;
    }
}

double Zoo::averageAgeForType(string _type) {
    double totalAge = 0;
    int count = 0;

    for (Animal* a : animals) {
        bool match = false;
        // Vérification dynamique du type
        if (_type == "Mammal" && dynamic_cast<Mammal*>(a)) match = true;
        else if (_type == "Bird" && dynamic_cast<Bird*>(a)) match = true;
        else if (_type == "Reptile" && dynamic_cast<Reptile*>(a)) match = true;

        if (match) {
            totalAge += a->getAge();
            count++;
        }
    }

    if (count == 0) return 0.0;
    return totalAge / count;
}

void Zoo::predictTypeWithKNN(Animal* _unknownAnimal, int _k, string _typeInfo) {
    cout << "--- KNN Prediction (" << _typeInfo << ") ---" << endl;

    // Ce vecteur stockera les indices des animaux les plus proches trouvés dans le Zoo
    vector<int> neighborsIndices;

    // --- CAS 1 : NUMERICAL (Poids, Taille) ---
    if (_typeInfo == "numerical") {
        // 1. Préparer les données d'entrainement (trainData)
        // On parcourt tous les animaux du Zoo et on extrait (Poids, Taille)
        vector<pair<double, double>> trainData;
        for (size_t i = 0; i < animals.size(); ++i) {
            trainData.push_back(make_pair(animals[i]->getWeight(), animals[i]->getHeight()));
        }

        // 2. Préparer la cible (target)
        pair<double, double> target = make_pair(_unknownAnimal->getWeight(), _unknownAnimal->getHeight());

        // 3. Lancer l'algo KNN
        KNNDouble knnSolver(_k);
        neighborsIndices = knnSolver.findNearestNeighbors(trainData, target);
    }
    // --- CAS 2 : CATEGORICAL (String Attributes) ---
    else if (_typeInfo == "categorical") {
        // 1. Préparer trainData (Vecteur de strings)
        vector<vector<string>> trainData;
        for (size_t i = 0; i < animals.size(); ++i) {
            Animal* a = animals[i];
            // On crée une liste {Color, Diet, Habitat, Sound} pour chaque animal
            vector<string> attributes;
            attributes.push_back(a->getColor());
            attributes.push_back(a->getDiet());
            attributes.push_back(a->getHabitat());
            attributes.push_back(a->getSound());

            trainData.push_back(attributes);
        }

        // 2. Préparer la cible
        vector<string> target;
        target.push_back(_unknownAnimal->getColor());
        target.push_back(_unknownAnimal->getDiet());
        target.push_back(_unknownAnimal->getHabitat());
        target.push_back(_unknownAnimal->getSound());

        // 3. Lancer l'algo KNN
        KNNString knnSolver(_k);
        neighborsIndices = knnSolver.findNearestNeighbors(trainData, target);
    }
    else {
        cout << "Error: Unknown type info '" << _typeInfo << "'" << endl;
        return;
    }

    // --- INTERPRÉTATION DES RÉSULTATS (Vote Majoritaire) ---

    int mammalCount = 0;
    int birdCount = 0;
    int reptileCount = 0;

    cout << "Nearest Neighbors found:" << endl;
    for (size_t i = 0; i < neighborsIndices.size(); ++i) {
        int index = neighborsIndices[i];
        Animal* neighbor = animals[index];

        cout << " - " << neighbor->getName() << " (Type: ";

        // On vérifie le type dynamique
        if (dynamic_cast<Mammal*>(neighbor)) {
            cout << "Mammal)";
            mammalCount++;
        } else if (dynamic_cast<Bird*>(neighbor)) {
            cout << "Bird)";
            birdCount++;
        } else if (dynamic_cast<Reptile*>(neighbor)) {
            cout << "Reptile)";
            reptileCount++;
        } else {
            cout << "Unknown)";
        }
        cout << endl;
    }

    // Décision finale
    cout << "Prediction Result: The unknown animal is likely a ";
    if (mammalCount >= birdCount && mammalCount >= reptileCount) {
        cout << "MAMMAL" << endl;
    } else if (birdCount >= mammalCount && birdCount >= reptileCount) {
        cout << "BIRD" << endl;
    } else {
        cout << "REPTILE" << endl;
    }
}
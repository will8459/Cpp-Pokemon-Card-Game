#include <iostream>
#include <vector>
#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include "Zoo.h"

using namespace std;

int main() {
    cout << "=============================" << endl;
    cout << " PHASE 1 : POPULATION DU ZOO " << endl;
    cout << " (Base d'entrainement) " << endl;
    cout << "=============================\n" << endl;

    Zoo myZoo("Zoo");
    Zoo::setMaxCapacity(50);

    // --- 1. L'animal Unknown ---
    Animal flash("Flash", "black", "Carnivore", "Mountains", "Mute", false, 9, 9.9, 1.8);
    myZoo.addAnimal(new Animal(flash));
    flash.printInfo();

    // --- 2. MAMMIFERES (Echelle variée) ---
    // Léger
    myZoo.addAnimal(new Mammal("Mouse", "White", "Omnivore", "House", "Squeak", true, 2, 0.1, 0.5, "Short"));
    // Moyens
    myZoo.addAnimal(new Mammal("Cat", "Black", "Carnivore", "House", "Meow", true, 3, 5.0, 1.0, "Soft"));
    myZoo.addAnimal(new Mammal("Dog", "Brown", "Carnivore", "House", "Bark", true, 5, 20.0, 1.5, "Short"));
    myZoo.addAnimal(new Mammal("Wolf", "Grey", "Carnivore", "Forest", "Howl", false, 6, 40.0, 2.0, "Thick"));
    // Lourds
    myZoo.addAnimal(new Mammal("Leo", "Golden", "Carnivore", "Grassland", "Roar", false, 5, 180.5, 3.5, "Tawny"));
    myZoo.addAnimal(new Mammal("Zebra", "Striped", "Herbivore", "Savanna", "Neigh", false, 4, 250.0, 3.8, "Striped"));
    // Géant
    myZoo.addAnimal(new Mammal("Elephant", "Grey", "Herbivore", "Savanna", "Trumpet", false, 20, 2000.0, 15.0, "Skin"));

    // --- 3. OISEAUX ---
    // Minuscule
    myZoo.addAnimal(new Bird("Hummingbird", "Green", "Nectar", "Garden", "Hum", false, 1, 0.01, 0.2, 0.3));
    // Communs
    myZoo.addAnimal(new Bird("Sparrow", "Brown", "Seeds", "City", "Chirp", false, 2, 0.03, 0.2, 0.2));
    myZoo.addAnimal(new Bird("Hawk", "Brown", "Carnivore", "Forest", "Screech", false, 7, 1.2, 45.0, 100.0));
    // "Lourd" pour un oiseau commun
    myZoo.addAnimal(new Bird("Eagle", "Brown", "Carnivore", "Mountains", "Screech", false, 8, 6.0, 1.2, 5.0));
    myZoo.addAnimal(new Bird("Swan", "White", "Herbivore", "Lake", "Trumpet", false, 12, 12.0, 1.1, 2.4));

    // --- 4. REPTILES ---
    // Léger
    myZoo.addAnimal(new Reptile("Iguana", "Green", "Herbivore", "Jungle", "Silence", true, 10, 5.0, 0.5, "Spikes"));
    myZoo.addAnimal(new Reptile("Viper", "Grey", "Carnivore", "Rocks", "Hiss", false, 4, 2.0, 5.0, "Zigzag"));
    // Moyen
    myZoo.addAnimal(new Reptile("Tortoise", "Brown", "Herbivore", "Island", "Grunt", false, 50, 50.0, 1.5, "Shell"));
    myZoo.addAnimal(new Reptile("Python", "Brown", "Carnivore", "Jungle", "Hiss", false, 15, 70.0, 30.0, "Scales"));
    // Lourd
    myZoo.addAnimal(new Reptile("Crocodile", "Grey", "Carnivore", "River", "Snap", false, 15, 240.0, 1.0, "Rough"));

    cout << endl;
    myZoo.listAnimals();
    cout << endl;


    cout << "\n=============================" << endl;
    cout << " PHASE 2 : TESTS DE PREDICTION " << endl;
    cout << "===============================" << endl;

    // ---------------------------------------------------------
    // TEST A : FLASH (L'ANIMAL UNKNOWN)
    // ---------------------------------------------------------
    cout << "\n[TEST A] 'FLASH'" << endl;

    cout << "-> (1) Numerical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&flash, 3, "numerical");
    cout << "-> (2) Categorical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&flash, 3, "categorical");


    // ---------------------------------------------------------
    // TEST B : SERPENT
    // ---------------------------------------------------------
    cout << "\n[TEST B] SNAKE" << endl;
    cout << ">>> Hypothese : REPTILE" << endl;

    Animal snake("Snake", "Green", "Carnivore", "Jungle", "Hiss", false, 5, 10.0, 0.);
    cout << "-> (1) Numerical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&snake, 3, "numerical");
    cout << "-> (2) Categorical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&snake, 3, "categorical");


    // ---------------------------------------------------------
    // TEST C : LE LAPIN
    // ---------------------------------------------------------
    cout << "\n[TEST C] RABBIT" << endl;
    cout << ">>> Hypothese : MAMMAL" << endl;

    Animal rabbit("Rabbit", "White", "Herbivore", "Garden", "Squeak", true, 2, 3.0, 1.0);

    cout << "-> (1) Numerical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&rabbit, 3, "numerical");
    cout << "-> (2) Categorical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&rabbit, 3, "categorical");


    // ---------------------------------------------------------
    // TEST D : TORTUE GEANTE
    // ---------------------------------------------------------
    cout << "\n[TEST D] TURTLE" << endl;
    cout << "Hypothese : REPTILE" << endl;

    Animal turtle("Turtle", "Green", "Herbivore", "Island", "Grunt", false, 100, 250.0, 2.0);

    cout << "-> (1) Numerical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&turtle, 3, "numerical");
    cout << "-> (2) Categorical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&turtle, 3, "categorical");


    // ---------------------------------------------------------
    // TEST E : HIPPOPOTAME
    // ---------------------------------------------------------
    cout << "\n[TEST E] HIPPO" << endl;
    cout << "Hypothese: MAMMAL" << endl;

    Animal hippo("Hippo", "Grey", "Herbivore", "River", "Grunt", false, 10, 1500.0, 10.0);

    cout << "-> (1) Numerical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&hippo, 3, "numerical");
    cout << "-> (2) Categorical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&hippo, 3, "categorical");

    // ---------------------------------------------------------
    // TEST F : HIBOU
    // ---------------------------------------------------------
    cout << "\n[TEST F] OWL" << endl;
    cout << "Hypothese: BIRD" << endl;

    Animal owl("Owl", "Brown", "Carnivore", "Barn", "Hoot", false, 4, 1.5, 0.6);
    cout << "-> (1) Numerical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&owl, 3, "numerical");
    cout << "-> (2) Categorical (k=3):" << endl;
    myZoo.predictTypeWithKNN(&owl, 3, "categorical");


    // --- TESTS FONCTIONNELS ZOO ---

    // Suppression
    cout << "Suppression of 'Flash'..." << endl;
    myZoo.removeAnimalByName("Flash");
    // myZoo.listAnimals();

    // Vérification Moyenne Age Mammiferes
    cout << "Mammal average age : " << myZoo.averageAgeForType("Mammal") << endl;
    return 0;
}
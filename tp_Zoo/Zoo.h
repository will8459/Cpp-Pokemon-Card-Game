#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Pour lower_bound

#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"

using namespace std;

class Zoo {
private:
    string name; // Nom du Zoo
    static int MAX_CAPACITY; // la capacite maximal du Zoo
    vector<Animal*> animals; // Les animaux dans le Zoo

public:
    Zoo();
    Zoo(string _name);
    Zoo(const Zoo& other); // copie (Deep Copy nécessaire)

    ~Zoo();

    string getName() const;
    void setName(const string& _name);

    static void setMaxCapacity(int _cap);

    void listAnimals() const;
    void addAnimal(Animal* _animal);
    int searchAnimalByName(string _name);
    void removeAnimalByName(string _name);
    double averageAgeForType(string _type);

    // 4 Utilisation de KNN
    void predictTypeWithKNN(Animal* _unknownAnimal, int _k, string _typeInfo);
};

#endif
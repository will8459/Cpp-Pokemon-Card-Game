#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

class Mammal : public Animal {
private:
    string furColor; // couleur de la fourrure

public:
    Mammal();
    Mammal(string _name, string _color, string _diet, string _habitat, 
           string _sounds, bool _isPet, int _age, double _weight, double _height,
           string _furColor);
    Mammal(const Mammal& other);

    virtual ~Mammal();

    string getFurColor() const;
    void setFurColor(const string& _furColor);

    void printInfo() const override;
};

#endif
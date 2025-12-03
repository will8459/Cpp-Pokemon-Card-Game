#include "Reptile.h"

Reptile::Reptile() : Animal(), scalePattern("Unknown") {}

Reptile::Reptile(string _name, string _color, string _diet, string _habitat, 
                 string _sounds, bool _isPet, int _age, double _weight, double _height,
                 string _scalePattern)
    : Animal(_name, _color, _diet, _habitat, _sounds, _isPet, _age, _weight, _height),
      scalePattern(_scalePattern) {
}

Reptile::Reptile(const Reptile& other) : Animal(other), scalePattern(other.scalePattern) {}

Reptile::~Reptile() {}

string Reptile::getScalePattern() const { return scalePattern; }
void Reptile::setScalePattern(const string& _scalePattern) { scalePattern = _scalePattern; }

void Reptile::printInfo() const {
    cout << "Animal of type Reptile:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;

    cout << "Scale Pattern : " << scalePattern << endl;
    
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}
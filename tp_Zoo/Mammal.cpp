#include "Mammal.h"

// Constructeur par défaut
Mammal::Mammal() 
    : Animal(), furColor("Unknown") {
}

Mammal::Mammal(string _name, string _color, string _diet, string _habitat, 
               string _sounds, bool _isPet, int _age, double _weight, double _height,
               string _furColor)
    : Animal(_name, _color, _diet, _habitat, _sounds, _isPet, _age, _weight, _height), 
      furColor(_furColor) {
}

Mammal::Mammal(const Mammal& other)
    : Animal(other), furColor(other.furColor) {
}

Mammal::~Mammal() {}

string Mammal::getFurColor() const { return furColor; }
void Mammal::setFurColor(const string& _furColor) { furColor = _furColor; }

void Mammal::printInfo() const {
    cout << "Animal of type Mammal:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;


    cout << "Fur Color : " << furColor << endl;

    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}
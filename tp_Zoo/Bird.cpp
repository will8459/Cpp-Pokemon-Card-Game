#include "Bird.h"

Bird::Bird() : Animal(), wingspan(0.0) {}

Bird::Bird(string _name, string _color, string _diet, string _habitat, 
           string _sounds, bool _isPet, int _age, double _weight, double _height,
           double _wingspan)
    : Animal(_name, _color, _diet, _habitat, _sounds, _isPet, _age, _weight, _height),
      wingspan(_wingspan) {
}

Bird::Bird(const Bird& other) : Animal(other), wingspan(other.wingspan) {}

Bird::~Bird() {}

double Bird::getWingspan() const { return wingspan; }
void Bird::setWingspan(double _wingspan) { wingspan = _wingspan; }

void Bird::printInfo() const {
    cout << "Animal of type Bird:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;

    cout << "Wingspan : " << wingspan << "cm" << endl; 
    
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}
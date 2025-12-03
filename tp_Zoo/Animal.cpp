#include "Animal.h"

Animal::Animal()
    : name("Unknown"), color("Unknown"), diet("Unknown"), habitat("Unknown"),
      sounds("Mute"), isPet(false), age(0), weight(0.0), height(0.0) {
}

Animal::Animal(string _name, string _color, string _diet, string _habitat,
               string _sounds, bool _isPet, int _age, double _weight, double _height)
    : name(_name), color(_color), diet(_diet), habitat(_habitat),
      sounds(_sounds), isPet(_isPet), age(_age), weight(_weight), height(_height) {
}

Animal::Animal(const Animal& other)
    : name(other.name), color(other.color), diet(other.diet), habitat(other.habitat),
      sounds(other.sounds), isPet(other.isPet), age(other.age), weight(other.weight), height(other.height) {
}

Animal::~Animal() {}

string Animal::getName() const { return name; }
void Animal::setName(const string& _name) { name = _name; }

string Animal::getColor() const { return color; }
void Animal::setColor(const string& _color) { color = _color; }

string Animal::getDiet() const { return diet; }
void Animal::setDiet(const string& _diet) { diet = _diet; }

string Animal::getHabitat() const { return habitat; }
void Animal::setHabitat(const string& _habitat) { habitat = _habitat; }

string Animal::getSound() const { return sounds; }
void Animal::setSounds(const string& _sounds) { sounds = _sounds; }

bool Animal::getIsPet() const { return isPet; }
void Animal::setIsPet(bool _isPet) { isPet = _isPet; }

int Animal::getAge() const { return age; }
void Animal::setAge(int _age) { age = _age; }

double Animal::getWeight() const { return weight; }
void Animal::setWeight(double _weight) { weight = _weight; }

double Animal::getHeight() const { return height; }
void Animal::setHeight(double _height) { height = _height; }

void Animal::make_sound() const {
    cout << sounds << endl;
}

void Animal::printInfo() const {
    cout << "Animal of unknown type:" << endl;
    cout << "Name : " << name << endl;
    cout << "Color : " << color << endl;
    cout << "Diet : " << diet << endl;
    cout << "Habitat : " << habitat << endl;
    cout << "Age : " << age << "'s old" << endl;
    cout << "This animal is " << (isPet ? "" : "not ") << "a pet" << endl;
    cout << "Weight : " << weight << "kg" << endl;
    cout << "Height : " << height << "cm" << endl;
}
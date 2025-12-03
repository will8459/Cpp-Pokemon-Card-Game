#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;    // nom de l'animal
    string color;   // couleur de l'animal
    string diet;    // regime alimentaire de l'animal
    string habitat; // habitat de l'animal
    string sounds;  // son de l'animal
    bool isPet;     // si l'animal est considere comme animal de compagnie
    int age;        // son age
    double weight;  // son poids
    double height;  // sa taille

public:
    // Constructeur par défaut
    Animal();
    // Constructeur paramétré
    Animal(string _name, string _color, string _diet, string _habitat,
           string _sounds, bool _isPet, int _age, double _weight, double _height);
    // Constructeur de copie
    Animal(const Animal& other);

    virtual ~Animal();

    // Getters / Setters
    string getName() const;
    void setName(const string& _name);

    string getColor() const;
    void setColor(const string& _color);

    string getDiet() const;
    void setDiet(const string& _diet);

    string getHabitat() const;
    void setHabitat(const string& _habitat);

    string getSound() const;
    void setSounds(const string& _sounds);

    bool getIsPet() const;
    void setIsPet(bool _isPet);

    int getAge() const;
    void setAge(int _age);

    double getWeight() const;
    void setWeight(double _weight);

    double getHeight() const;
    void setHeight(double _height);

    // Fonctions
    void make_sound() const;
    virtual void printInfo() const;
};

#endif
#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

class Reptile : public Animal {
private:
    string scalePattern; // Motif d'écailles du reptile

public:
    Reptile();
    Reptile(string _name, string _color, string _diet, string _habitat, 
            string _sounds, bool _isPet, int _age, double _weight, double _height,
            string _scalePattern);
    Reptile(const Reptile& other);

    virtual ~Reptile();

    string getScalePattern() const;
    void setScalePattern(const string& _scalePattern);

    void printInfo() const override;
};

#endif
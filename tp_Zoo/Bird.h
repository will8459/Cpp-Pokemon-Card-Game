#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

class Bird : public Animal {
private:
    double wingspan; // envergure

public:
    Bird();
    Bird(string _name, string _color, string _diet, string _habitat, 
         string _sounds, bool _isPet, int _age, double _weight, double _height,
         double _wingspan);
    Bird(const Bird& other);

    virtual ~Bird();

    double getWingspan() const;
    void setWingspan(double _wingspan);

    void printInfo() const override;
};

#endif
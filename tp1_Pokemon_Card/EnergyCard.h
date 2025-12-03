#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>
using namespace std;


class EnergyCard : public Card {
private:
    string energyType;
public:
    EnergyCard(const string& energyType);
    void displayInfo() override;
    string getEnergyType() const;
};


#endif //ENERGYCARD_H
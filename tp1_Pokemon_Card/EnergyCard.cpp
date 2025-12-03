#include "EnergyCard.h"

EnergyCard::EnergyCard(const string& _energyType):
Card("Energy"), energyType(_energyType)
{}

void EnergyCard::displayInfo() {
    cout << "Energy Card - Type: " << energyType << endl;
}

string EnergyCard::getEnergyType() const {
    return energyType;
}
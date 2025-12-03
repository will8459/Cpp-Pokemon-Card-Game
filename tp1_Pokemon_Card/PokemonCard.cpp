#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(
    const string& _pokemonName,
    const string& _pokemonType,
    const string& _familyName,
    unsigned int _evolutionLevel,
    unsigned int _maxHP,
    int _cost1, string _desc1, int _dmg1,
    int _cost2, string _desc2, int _dmg2
    ):
Card(_pokemonName),
pokemonType(_pokemonType),
familyName(_familyName),
evolutionLevel(_evolutionLevel),
maxHP(_maxHP), hp(_maxHP)
{
    attacks.push_back(make_tuple(_cost1, 0, _desc1, _dmg1));
    attacks.push_back(make_tuple(_cost2, 0, _desc2, _dmg2));
}

void PokemonCard::displayInfo() {
    cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
         << ", Evolution Level: " << evolutionLevel << " of the family \"" << familyName
         << "\", HP: " << hp << "\"" << endl;

    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl;
        cout << "Attack current energy storage: " << get<1>(attacks[i]) << endl;
        cout << "Attack description: " << get<2>(attacks[i]) << endl;
        cout << "Attack damage: " << get<3>(attacks[i]) << endl;
    }
}

unsigned int PokemonCard::getMaxHP() const {
    return maxHP;
}
unsigned int PokemonCard::getHp() const{
    return hp;
}

void PokemonCard::setHp(unsigned int newHp) {
    hp = newHp;
}

void PokemonCard::attack(int attackIndex, PokemonCard* target) const {
    if (attackIndex >= attacks.size()) return;

    int cost = get<0>(attacks[attackIndex]);
    int currentEnergy = get<1>(attacks[attackIndex]);
    string desc = get<2>(attacks[attackIndex]);
    int dmg = get<3>(attacks[attackIndex]);

    if (currentEnergy < cost) {
        cout << "Not enough energy to attack!" << endl;
        return;
    }

    cout << desc << endl;

    target->takeDamage(dmg);
}

void PokemonCard::takeDamage(const int dmg) {
    if (dmg > hp) {
        hp = 0;
    } else {
        hp = hp - dmg;
    }

    cout << "Reducing " << dmg << " from " << cardName << "'s Pokemon's HP" << endl;
    if (hp == 0) {
        cout << "Pokemon " << cardName << " is dead" << endl;
    } else {
        cout << "Pokemon " << cardName << " is still alive" << endl;
    }
}

void PokemonCard::addEnergy() {
    for (unsigned int i = 0; i < attacks.size(); i++) {
        get<1>(attacks[i]) = get<1>(attacks[i]) + 1;
    }
}

void PokemonCard::heal() {
    hp = maxHP;
}


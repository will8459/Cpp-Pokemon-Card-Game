#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class PokemonCard : public Card{
private:
    string pokemonType;
    string familyName;
    unsigned int evolutionLevel;
    unsigned int maxHP;
    unsigned int hp;
    vector<tuple<unsigned int, unsigned int, string, unsigned int>> attacks;
public:
    PokemonCard(
        const string& pokemonName,
        const string& pokemonType,
        const string& familyName,
        unsigned int evolutionLevel,
        unsigned intmaxHP,
        int cost1, string desc1, int dmg1,
        int cost2, string desc2, int dmg2);
    void displayInfo() override;
    unsigned int getMaxHP() const;
    unsigned int getHp() const;
    void setHp(unsigned int newHp);

    void attack(int attackIndex, PokemonCard* target) const;
    void takeDamage(int dmg);
    void addEnergy();
    void heal();
};


#endif //POKEMONCARD_H
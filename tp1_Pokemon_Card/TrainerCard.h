#ifndef TRAINERCARD_H
#define TRAINERCARD_H
#include "Card.h"
#include "PokemonCard.h"
#include <string>
#include <vector>
using namespace std;



class TrainerCard : public Card{
private:
    string trainerEffect;
public:
    TrainerCard(const string& trainerName, const string& trainerEffect);
    void displayInfo() override;
    void healAll(const vector<PokemonCard*>& actionCards) const;
};


#endif //TRAINERCARD_H
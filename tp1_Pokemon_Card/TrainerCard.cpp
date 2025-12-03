#include "TrainerCard.h"

TrainerCard::TrainerCard(const string& _trainerName, const string& _trainerEffect):
Card(_trainerName), trainerEffect(_trainerEffect)
{
}

void TrainerCard::displayInfo() {
    cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << endl;
}

void TrainerCard::healAll(const vector<PokemonCard*>& actionCards) const {
    cout << "to \"" << trainerEffect << "\"" << endl;

    for (PokemonCard* p : actionCards) {
        p->heal();
    }
}


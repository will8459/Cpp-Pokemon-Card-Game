#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <iostream>

Player::Player(string _playerName):
playerName(_playerName)
{
}

Player::~Player() {
    for (Card* _benchCard : benchCards) delete _benchCard;
    for (Card* _actionCard : actionCards) delete _actionCard;
    benchCards.clear();
    actionCards.clear();
}

void Player::addCardToBench(Card* newCard) {
    benchCards.push_back(newCard);
}

void Player::activatePokemonCard(int index) {
    if (index >= benchCards.size()) return;

    Card* c = benchCards[index];
    PokemonCard* pc = dynamic_cast<PokemonCard*>(c);

    if (pc != nullptr) {
        cout << playerName << " is activating a Pokemon Card: " << pc->getName() << endl;
        actionCards.push_back(pc);
        benchCards.erase(benchCards.begin() + index);
    }
}

void Player::attachEnergyCard(int indexBench, int indexAction) {
    if (indexBench >= benchCards.size() || indexAction >= actionCards.size()) return;

    Card* c = benchCards[indexBench];
    EnergyCard* ec = dynamic_cast<EnergyCard*>(c);

    if (ec != nullptr) {
        cout << playerName << " is attaching Energy Card of type " << ec->getEnergyType()
             << " to the Pokemon " << actionCards[indexAction]->getName() << endl;

        actionCards[indexAction]->addEnergy();

        delete ec;
        benchCards.erase(benchCards.begin() + indexBench);
    }
}

void Player::useTrainer(int indexBench) {
    if (indexBench >= benchCards.size()) return;

    Card* c = benchCards[indexBench];
    TrainerCard* tc = dynamic_cast<TrainerCard*>(c);

    if (tc != nullptr) {
        cout << playerName << " is using the Trainer Card ";
        tc->healAll(actionCards);

        delete tc;
        benchCards.erase(benchCards.begin() + indexBench);
    }
}

void Player::attack(int myActiveIndex, int atkIndex, Player& opponent, int oppActiveIndex) {
    if (myActiveIndex >= actionCards.size()) return;

    PokemonCard* myPoke = actionCards[myActiveIndex];
    PokemonCard* oppPoke = opponent.getActivePokemon(oppActiveIndex);

    if (myPoke && oppPoke) {
        cout << playerName << " attacking " << opponent.getName() << "'s Pokemon "
             << oppPoke->getName() << " with the Pokemon " << myPoke->getName()
             << " with its attack: ";

        myPoke->attack(atkIndex, oppPoke);
    }
}

void Player::displayBench() {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (Card* c : benchCards) {
        c->displayInfo();
    }
}

void Player::displayAction() {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (PokemonCard* pc : actionCards) {
        pc->displayInfo();
    }
}

PokemonCard* Player::getActivePokemon(int index) {
    if (index < actionCards.size()) {
        return actionCards[index];
    }
    return nullptr;
}

string Player::getName() const {
    return playerName;
}
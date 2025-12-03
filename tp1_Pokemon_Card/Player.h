#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
using namespace std;


class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;
public:
    Player(string playerName);
    ~Player();

    void addCardToBench(Card* newCard);
    void activatePokemonCard(int index);
    void attachEnergyCard(int indexBench, int indexAction);
    void useTrainer(int indexBench);
    void attack(int myActiveIndex, int atkIndex, Player& opponent, int oppActiveIndex);

    void displayBench();
    void displayAction();

    PokemonCard* getActivePokemon(int index);
    string getName() const;
};


#endif //PLAYER_H
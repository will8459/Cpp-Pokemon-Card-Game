#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card {
protected:
    string cardName;
public:
    virtual ~Card();

    Card(const string&);
    virtual void displayInfo() = 0;
    const string getName() const;
};


#endif //CARD_H
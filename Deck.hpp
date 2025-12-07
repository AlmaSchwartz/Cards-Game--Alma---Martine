#ifndef DECK_H
#define DECK_H
#include "Card.hpp"
#include <string>

class Deck
{
private:
    Card *cards;
    int cardCount;

public:
    Deck();
    Deck(const Deck &other);
    Deck &operator=(const Deck &other);
    ~Deck();

    void populateDeckFromFile(const std::string &filename);

    void addCard(const Card &c);

    Card draw();
    bool isEmpty() const;
    void shuffle();

    int getCardCount() const { return cardCount; }
};

#endif

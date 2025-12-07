#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.hpp"

class Player
{
private:
    char *name;
    Deck hand; // The player's hand of cards

public:
    // Constructor
    Player(const char *n = "");

    // Copy constructor
    Player(const Player &other);

    // Assignment operator
    Player &operator=(const Player &other);

    // Destructor
    ~Player();

    // Receive a card into the player's hand
    void receiveCard(const Card &c);

    // Play (draw) a card from the player's hand
    Card playCard();

    // Check if the player still has cards
    bool hasCards() const;

    // Get player name
    const char *getName() const;
};

#endif // PLAYER_H

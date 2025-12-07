#include "Player.hpp"
#include <cstring>
#include <iostream>

// Constructor
Player::Player(const char *n)
    : name(nullptr), hand()
{
    if (n == nullptr)
    {
        name = new char[1];
        name[0] = '\0';
    }
    else
    {
        size_t len = std::strlen(n);
        name = new char[len + 1];
        std::strcpy(name, n);
    }
}

// Copy constructor
Player::Player(const Player &other)
    : name(nullptr), hand(other.hand)
{
    if (other.name == nullptr)
    {
        name = nullptr;
    }
    else
    {
        size_t len = std::strlen(other.name);
        name = new char[len + 1];
        std::strcpy(name, other.name);
    }
}

// Assignment operator
Player &Player::operator=(const Player &other)
{
    if (this == &other)
        return *this;

    // Free old name
    delete[] name;
    name = nullptr;

    // Copy name
    if (other.name == nullptr)
    {
        name = nullptr;
    }
    else
    {
        size_t len = std::strlen(other.name);
        name = new char[len + 1];
        std::strcpy(name, other.name);
    }

    // Copy hand (Deck has its own operator= with deep copy)
    hand = other.hand;

    return *this;
}

// Destructor
Player::~Player()
{
    delete[] name;
    name = nullptr;
}

// Receive a card into the hand
void Player::receiveCard(const Card &c)
{
    hand.addCard(c);
}

// Play (draw) a card from the hand
Card Player::playCard()
{
    if (!hasCards())
    {
        // No cards – return default card
        return Card();
    }

    return hand.draw();
}

// Check if player has cards
bool Player::hasCards() const
{
    return !hand.isEmpty();
}

// Get player name
const char *Player::getName() const
{
    return name;
}

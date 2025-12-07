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

    delete[] name;
    name = nullptr;

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

    hand = other.hand;

    return *this;
}

// Destructor
Player::~Player()
{
    delete[] name;
    name = nullptr;
}

void Player::receiveCard(const Card &c)
{
    hand.addCard(c);
}

Card Player::playCard()
{
    if (!hasCards())
    {
        return Card();
    }

    return hand.draw();
}

bool Player::hasCards() const
{
    return !hand.isEmpty();
}

const char *Player::getName() const
{
    return name;
}

#include "Card.hpp"
#include <cstring>
#include <iostream>

// Default constructor
Card::Card()
    : suit(HEARTS), rank(nullptr)
{
    rank = new char[1];
    rank[0] = '\0';
}

// Regular constructor
Card::Card(Suit nsuit, const char *nrank)
    : suit(nsuit), rank(nullptr)
{
    if (nrank == nullptr)
    {
        rank = new char[1];
        rank[0] = '\0';
    }
    else
    {
        size_t len = std::strlen(nrank);
        rank = new char[len + 1];
        std::strcpy(rank, nrank);
    }
}

// Copy constructor – deep copy
Card::Card(const Card &other)
    : suit(other.suit), rank(nullptr)
{
    if (other.rank == nullptr)
    {
        rank = nullptr;
    }
    else
    {
        size_t len = std::strlen(other.rank);
        rank = new char[len + 1];
        std::strcpy(rank, other.rank);
    }
}

// Assignment operator
Card &Card::operator=(const Card &other)
{
    if (this == &other)
    {
        return *this; // self-assignment
    }

    // משחררים את מה שהיה קודם
    delete[] rank;
    rank = nullptr;

    suit = other.suit;

    if (other.rank == nullptr)
    {
        rank = nullptr;
    }
    else
    {
        size_t len = std::strlen(other.rank);
        rank = new char[len + 1];
        std::strcpy(rank, other.rank);
    }

    return *this;
}

// Destructor
Card::~Card()
{
    delete[] rank;
}

// Getters
Suit Card::getSuit() const
{
    return suit;
}

const char *Card::getRank() const
{
    return rank;
}

// Print
void Card::print() const
{
    std::cout << "Card: ";

    switch (suit)
    {
    case HEARTS:
        std::cout << "Hearts";
        break;
    case SPADES:
        std::cout << "Spades";
        break;
    case DIAMONDS:
        std::cout << "Diamonds";
        break;
    case CLUBS:
        std::cout << "Clubs";
        break;
    }

    std::cout << ", " << (rank ? rank : "") << std::endl;
}
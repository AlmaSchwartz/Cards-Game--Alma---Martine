#include "Deck.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <iostream>

Deck::Deck()
    : cards(nullptr), cardCount(0)
{
}

// Destructor
Deck::~Deck()
{
    delete[] cards;
    cards = nullptr;
    cardCount = 0;
}

Deck::Deck(const Deck &other)
    : cards(nullptr), cardCount(other.cardCount)
{
    if (cardCount > 0)
    {
        cards = new Card[cardCount];
        for (int i = 0; i < cardCount; ++i)
        {
            cards[i] = other.cards[i];
        }
    }
}

Deck &Deck::operator=(const Deck &other)
{
    if (this == &other)
        return *this;

    delete[] cards;
    cards = nullptr;

    cardCount = other.cardCount;

    if (cardCount > 0)
    {
        cards = new Card[cardCount];
        for (int i = 0; i < cardCount; ++i)
        {
            cards[i] = other.cards[i];
        }
    }

    return *this;
}

void Deck::populateDeckFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "File not found: " << filename << std::endl;
        return;
    }

    std::string line;
    int count = 0;

    while (std::getline(file, line))
    {
        if (!line.empty())
            ++count;
    }

    delete[] cards;
    cards = nullptr;
    cardCount = 0;

    if (count == 0)
    {
        return;
    }

    cards = new Card[count];
    cardCount = 0;

    file.clear();
    file.seekg(0);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string suitStr, rankStr;

        std::getline(ss, suitStr, ',');
        std::getline(ss, rankStr);

        if (!rankStr.empty() && rankStr[0] == ' ')
            rankStr.erase(0, 1);

        Suit s;
        if (suitStr == "Hearts")
            s = HEARTS;
        else if (suitStr == "Diamonds")
            s = DIAMONDS;
        else if (suitStr == "Clubs")
            s = CLUBS;
        else
            s = SPADES;

        cards[cardCount++] = Card(s, rankStr.c_str());
    }

    file.close();
}

void Deck::addCard(const Card &c)
{
    Card *newCards = new Card[cardCount + 1];

    for (int i = 0; i < cardCount; ++i)
    {
        newCards[i] = cards[i];
    }

    newCards[cardCount] = c;

    delete[] cards;

    cards = newCards;

    ++cardCount;
}

Card Deck::draw()
{
    if (cardCount == 0)
    {
        return Card();
    }

    return cards[--cardCount];
}

bool Deck::isEmpty() const
{
    return cardCount == 0;
}

void Deck::shuffle()
{
    if (cards == nullptr || cardCount <= 1)
        return;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards, cards + cardCount, g);
}

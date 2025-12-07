#include "Game.hpp"
#include <iostream>
#include <string>

// Constructor
Game::Game(const Player &p1, const Player &p2)
    : player1(p1), player2(p2), score1(0), score2(0)
{
}

// Copy constructor
Game::Game(const Game &other)
    : player1(other.player1),
      player2(other.player2),
      score1(other.score1),
      score2(other.score2)
{
}

Game &Game::operator=(const Game &other)
{
    if (this == &other)
        return *this;

    player1 = other.player1;
    player2 = other.player2;
    score1 = other.score1;
    score2 = other.score2;

    return *this;
}

// Destructor
Game::~Game()
{
    // Nothing special to do – members clean themselves
}

void Game::start()
{
    std::cout << "Starting War game between "
              << player1.getName() << " and "
              << player2.getName() << "!" << std::endl;
}

void Game::playRound()
{
    if (!player1.hasCards() || !player2.hasCards())
    {
        std::cout << "No more cards to play a round." << std::endl;
        return;
    }

    Card c1 = player1.playCard();
    Card c2 = player2.playCard();

    int v1 = getCardValue(c1);
    int v2 = getCardValue(c2);

    std::cout << player1.getName() << " plays: ";
    c1.print();

    std::cout << player2.getName() << " plays: ";
    c2.print();

    if (v1 > v2)
    {
        ++score1;
        std::cout << player1.getName() << " wins the round!" << std::endl;
    }
    else if (v2 > v1)
    {
        ++score2;
        std::cout << player2.getName() << " wins the round!" << std::endl;
    }
    else
    {
        std::cout << "Round is a tie." << std::endl;
    }

    std::cout << "Score: "
              << player1.getName() << " = " << score1
              << ", " << player2.getName() << " = " << score2
              << std::endl
              << std::endl;
}

int Game::checkWinner() const
{
    if (player1.hasCards() || player2.hasCards())
    {
        return 0;
    }

    if (score1 > score2)
        return 1;
    if (score2 > score1)
        return 2;

    return 1;
}

int Game::getCardValue(const Card &c) const
{
    std::string r = c.getRank();

    if (r == "2")
        return 2;
    if (r == "3")
        return 3;
    if (r == "4")
        return 4;
    if (r == "5")
        return 5;
    if (r == "6")
        return 6;
    if (r == "7")
        return 7;
    if (r == "8")
        return 8;
    if (r == "9")
        return 9;
    if (r == "10")
        return 10;
    if (r == "Jack")
        return 11;
    if (r == "Queen")
        return 12;
    if (r == "King")
        return 13;
    if (r == "Ace")
        return 14;

    return 0;
}

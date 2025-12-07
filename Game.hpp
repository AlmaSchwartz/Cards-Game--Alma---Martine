#ifndef GAME_H
#define GAME_H

#include "Player.hpp"
#include "Deck.hpp"

class Game
{
private:
    Player player1;
    Player player2;
    int score1;
    int score2;

public:
    // Constructor – gets two players (by value)
    Game(const Player &p1, const Player &p2);

    // Copy constructor
    Game(const Game &other);

    // Assignment operator
    Game &operator=(const Game &other);

    // Destructor
    ~Game();

    // Start the game (can print initial info)
    void start();

    // Play a single round
    void playRound();

    // Check winner:
    // 0 – no winner yet
    // 1 – player1 wins
    // 2 – player2 wins
    int checkWinner() const;

private:
    // Helper: convert card rank to numeric value
    int getCardValue(const Card &c) const;
};

#endif // GAME_H

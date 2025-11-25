#ifndef CARD_H
#define CARD_H
#include <iostream>

enum Suit{
          HEARTS,
          SPADES,
          DIAMONDS,
          CLUBS
};

class Card
{
private:
         Suit suit;
         char* rank;
public:
          Card();
          Card(Suit suit, const char* rank);
          Card(const Card& other);
          Card& operator=(const Card& other);
          ~Card();

          Suit getSuit() const;
          const char* getRank() const;
          void print() const;
};

#endif
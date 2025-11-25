#ifndef DECK_HPP
#define DECK_HPP

#include <cstring>
#include "Card.hpp"

class Deck
{
private:
          Card* cards;
          int cardCount;
public:
          Deck();
          Deck(const Deck& other);
          Deck& operator=(const Deck& other);
          ~Deck();

          void populateDeckFromFile(const std::string& filename);
          void shuffle();
          Card draw();
          bool isEmpty() const;
};
#endif


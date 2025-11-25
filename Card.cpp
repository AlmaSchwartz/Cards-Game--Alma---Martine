#include "Card.hpp"
#include <cstring>
#include <ostream>

//default constructor
Card::Card():suit(HEARTS){

          rank= new char[1];
          rank[0]='\0';

}

//Regular constructor
Card::Card(Suit nsuit, const char* nrank)
: suit(nsuit){
          if(rank==nullptr){
            rank= new char[1];
            rank[0]='\0';        
          }else{
                    size_t len= std:: strlen(nrank);
                    rank= new char[len+1];
                    std::strcpy(rank,nrank);
          }

}

//Copy Constructor- Deep Copy

Card::Card(const Card& other)
: suit(other.suit){
          if(other.rank==nullptr){
                    rank=nullptr;
          }else{
                    size_t len= std:: strlen(other.rank);
                    rank= new char[len+1];
                    std:: strcpy(rank,other.rank);

          }
}

//Operator = 
Card& Card:: operator=(const Card& other){
          if(this==&other){
                    return *this;
          }
          delete[] rank;
          suit=other.suit;

          if(other.rank==nullptr){
                    rank=nullptr;
          }else{
                    size_t len= std::strlen(other.rank);
                    rank=new char[len+1];
                    std::strcpy(rank,other.rank);
          }
          return *this;

}

//Destructor
Card::~Card(){
          delete[]rank;
}

//Getters

Suit Card::getSuit() const{
          return suit;
}

const char* Card::getRank() const{
          return rank;
}

//Print
void Card::print() const{
          std::cout<< "Card: ";
          switch(suit){
                    case HEARTS: std::cout<<"Hearts"; 
                              break;
                    case SPADES: std::cout<<"Spades"; 
                              break;
                    case DIAMONDS: std::cout<<"Diamonds";
                              break;
                    case CLUBS: std::cout<<"Clubs";
                              break;
          }
          std::cout<<", "<< rank << std::endl;
}
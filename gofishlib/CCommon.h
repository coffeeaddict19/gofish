#ifndef CCOMMON_H
#define CCOMMON_H

enum eErrors{
    NoError = 0,
    AllocationFail = 1,
    IsHumanPlayersTurn = 2,
    InvalidArg = 3,
    GameIsAlreadyOver = 4,
    NotImplemented = 5,
    IsAIPlayersTurn = 6
};

const unsigned char kNumberOfPlayers = 5;
enum ePlayers{
  Human = 0,
  Dan = 1,
  Judy = 2,
  Danielle = 3,
  Nicholas = 4
};

enum ePlayer{
    Interactive = 0,
    AI = 1
};

enum eCard{
  Card2 = 0,
  Card3 = 1,
  Card4 = 2,
  Card5 = 3,
  Card6 = 4,
  Card7 = 5,
  Card8 = 6,
  Card9 = 7,
  Card10 = 8,
  CardJack = 9,
  CardQueen = 10,
  CardKing = 11,
  CardAce = 12
};

enum eSuit{
  Clubs = 0,
  Diamonds = 1,
  Hearts = 2,
  Spades = 3
};

//struct Card{
//  unsigned char CardType_;
//  unsigned char SuitType_;
//};

typedef unsigned char Card;

#endif

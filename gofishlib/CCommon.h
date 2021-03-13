#ifndef CCOMMON_H
#define CCOMMON_H

enum eErrors{
    NoError = 0,
    AllocationFail = 1,
    InvalidArg = 2,
    GameIsAlreadyOver = 3,
    NotImplemented = 4
};

enum eTurnResult{
  Win = 0,
  Lose = 1,
  GoFishReturnedCardsYouGetAnotherTurn = 2,
  GoFishReturnedNoCardsYourTurnIsOver = 3
};

const unsigned char kNumberOfPlayers = 5;
const unsigned char kNumberOfCardsInDeck = 52;
const unsigned char kNumberOfCardsInBook = 4;
enum ePlayers{
  John = 0,
  Dan = 1,
  Judy = 2,
  Danielle = 3,
  Nicholas = 4
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

typedef unsigned char Card;

struct CardWithInitFlag{
  Card Card_;
  bool Initialized_;
};

typedef void* CardCollectionVoidPtr;

struct CardCollection{
  CardCollectionVoidPtr CardCollection_;
  void (*Destroy)(CardCollection* PtrToCardCollection);
  unsigned char (*Size)(CardCollection* PtrToCardCollection);
  CardWithInitFlag (*At)(CardCollection* PtrToCardCollection, unsigned char Index);
  void (*Push)(CardCollection* PtrToCardCollection, Card C);
};

typedef void* GamePtr;

struct PlayerInput{
  Card RequestedCard_;
  ePlayers PlayerToRequestCardOf_;
};

struct PlayerOutput{
  eTurnResult TurnResult_;
  eErrors Error_;
  ePlayers PlayerGoFishCardsWereReceivedFrom_;
  CardCollection CopyOfGoFishCardsReceived_;
  CardCollection CopyOfCards_;
};

typedef void* LoggerPtr;

struct Logger{
    LoggerPtr LoggerPtr_;
    void (*Destroy)(Logger* PtrToLogger);
};

struct Context{
  GamePtr GamePtr_;
  Logger* Logger_;
  void (*SetLogger)(Context* PtrToContext, Logger* PtrToLogger);
  void (*Destroy)(Context* PtrToContext);
  PlayerOutput (*Play)(Context* PtrToContext, PlayerInput* Inputs);
};

#endif

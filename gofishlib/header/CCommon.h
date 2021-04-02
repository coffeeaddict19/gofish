#ifndef CCOMMON_H
#define CCOMMON_H

#include <stdbool.h>

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

#define kNumberOfPlayers 5
#define kNumberOfCardsInDeck 52
#define kNumberOfCardsInBook 4
#define kNumberOfCardsToDealPerPlayer 5

/*
          ACE   2   3   4   5   6   7   8   9   10   J   Q   K
Clubs     0     4   8   12  16  20  24  28  32  36   40  44  48
Diamonds  1     5   9   13  17  21  25  29  33  37   41  45  49
Hearts    2     6   10  14  18  22  26  30  34  38   42  46  50
Spades    3     7   11  15  19  23  27  31  35  39   43  47  51
*/

#define CARD_A_CLUB 0
#define CARD_A_DIAMOND 1
#define CARD_A_HEART 2
#define CARD_A_SPADE 3
#define CARD_2_CLUB 4
#define CARD_2_DIAMOND 5
#define CARD_2_HEART 6
#define CARD_2_SPADE 7
#define CARD_3_CLUB 8
#define CARD_3_DIAMOND 9
#define CARD_3_HEART 10
#define CARD_3_SPADE 11
#define CARD_4_CLUB 12
#define CARD_4_DIAMOND 13
#define CARD_4_HEART 14
#define CARD_4_SPADE 15
#define CARD_5_CLUB 16
#define CARD_5_DIAMOND 17
#define CARD_5_HEART 18
#define CARD_5_SPADE 19
#define CARD_6_CLUB 20
#define CARD_6_DIAMOND 21
#define CARD_6_HEART 22
#define CARD_6_SPADE 23
#define CARD_7_CLUB 24
#define CARD_7_DIAMOND 25
#define CARD_7_HEART 26
#define CARD_7_SPADE 27
#define CARD_8_CLUB 28
#define CARD_8_DIAMOND 29
#define CARD_8_HEART 30
#define CARD_8_SPADE 31
#define CARD_9_CLUB 32
#define CARD_9_DIAMOND 33
#define CARD_9_HEART 34
#define CARD_9_SPADE 35
#define CARD_10_CLUB 36
#define CARD_10_DIAMOND 37
#define CARD_10_HEART 38
#define CARD_10_SPADE 39
#define CARD_J_CLUB 40
#define CARD_J_DIAMOND 41
#define CARD_J_HEART 42
#define CARD_J_SPADE 43
#define CARD_Q_CLUB 44
#define CARD_Q_DIAMOND 45
#define CARD_Q_HEART 46
#define CARD_Q_SPADE 47
#define CARD_K_CLUB 48
#define CARD_K_DIAMOND 49
#define CARD_K_HEART 50
#define CARD_K_SPADE 51

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

struct CardCollection;

struct CardCollection{
  CardCollectionVoidPtr CardCollection_;
  void (*Destroy)(struct CardCollection* PtrToCardCollection);
  unsigned char (*Size)(struct CardCollection* PtrToCardCollection);
  Card (*At)(struct CardCollection* PtrToCardCollection, unsigned char Index);
  void (*Push)(struct CardCollection* PtrToCardCollection, Card C);
};

typedef void* GamePtr;

struct PlayerInput{
  Card RequestedCard_;
  enum ePlayers ThisPlayer_;
  enum ePlayers PlayerToRequestCardOf_;
};

struct PlayerOutput{
  enum eTurnResult TurnResult_;
  enum eErrors Error_;
  enum ePlayers NextPlayer_;
  enum ePlayers PlayerGoFishCardsWereReceivedFrom_;
  struct CardCollection CopyOfGoFishCardsReceived_;
  struct CardCollection CopyOfCards_;
};

struct Context;

struct Context{
  GamePtr GamePtr_;
  void (*Destroy)(struct Context* PtrToContext);
  struct PlayerOutput (*Play)(struct Context* PtrToContext, struct PlayerInput* Inputs);
  struct CardCollection (*GetPlayersCopyOfCards)(struct Context* PtrToContext, enum ePlayers Player);
};

#endif

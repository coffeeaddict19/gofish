#include "ctest.h"
#include "ExternalSymbols.h"
#include <stdlib.h>

/*
          ACE   2   3   4   5   6   7   8   9   10   J   Q   K
Clubs     0     4   8   12  16  20  24  28  32  36   40  44  48
Diamonds  1     5   9   13  17  21  25  29  33  37   41  45  49
Hearts    2     6   10  14  18  22  26  30  34  38   42  46  50
Spades    3     7   11  15  19  23  27  31  35  39   43  47  51
*/

CTEST_DATA(DeckOfCards) {
  Card (*NotShuffled_)[kNumberOfCardsInDeck];
  Card (*Shuffled_)[kNumberOfCardsInDeck];
};

CTEST_SETUP(DeckOfCards) {
  data->NotShuffled_ = malloc(sizeof(*data->NotShuffled_));
  for(int Index=0; Index<kNumberOfCardsInDeck; Index++){
    (*data->NotShuffled_)[Index] = (Card)Index;
  }
  Card Shuffled[kNumberOfCardsInDeck] = {
    9,  41, 39,  30,  4,  5, 13,  7,  8, 33,
    3,  11, 12,  6,  14, 50, 26, 46, 18, 51,
    20, 29, 22,  23, 24, 25, 16, 27, 28, 21,
    10, 31, 32,  0,  34, 45, 36, 37, 38,  2,
    40, 1,  42,  43, 44, 35, 17, 47, 48, 49, 15, 19
  };
  data->Shuffled_ = malloc(sizeof(*data->Shuffled_));
  for(int Index=0; Index<kNumberOfCardsInDeck; Index++){
    (*data->Shuffled_)[Index] = Shuffled[Index];
  }
}

CTEST_TEARDOWN(DeckOfCards) {
  free(data->NotShuffled_);
  free(data->Shuffled_);
}

CTEST2(DeckOfCards, DealDeckNotShuffledFirstPlayerStart) {
  struct Context GameContext = NewContext(data->NotShuffled_, John);
  ASSERT_EQUAL(NoError, GameContext.Errors_);
  struct CardCollection JohnCards = GameContext.GetPlayersCopyOfCards(&GameContext, John);
  struct CardCollection DanCards = GameContext.GetPlayersCopyOfCards(&GameContext, Dan);
  struct CardCollection JudyCards = GameContext.GetPlayersCopyOfCards(&GameContext, Judy);
  struct CardCollection DanielleCards = GameContext.GetPlayersCopyOfCards(&GameContext, Danielle);
  struct CardCollection NicholasCards = GameContext.GetPlayersCopyOfCards(&GameContext, Nicholas);
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JohnCards.Size(&JohnCards));
  ASSERT_EQUAL(0, JohnCards.At(&JohnCards, 0));
  ASSERT_EQUAL(1, JohnCards.At(&JohnCards, 1));
  ASSERT_EQUAL(2, JohnCards.At(&JohnCards, 2));
  ASSERT_EQUAL(3, JohnCards.At(&JohnCards, 3));
  ASSERT_EQUAL(4, JohnCards.At(&JohnCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanCards.Size(&DanCards));
  ASSERT_EQUAL(5, JohnCards.At(&DanCards, 0));
  ASSERT_EQUAL(6, JohnCards.At(&DanCards, 1));
  ASSERT_EQUAL(7, JohnCards.At(&DanCards, 2));
  ASSERT_EQUAL(8, JohnCards.At(&DanCards, 3));
  ASSERT_EQUAL(9, JohnCards.At(&DanCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JudyCards.Size(&JudyCards));
  ASSERT_EQUAL(10, JohnCards.At(&JudyCards, 0));
  ASSERT_EQUAL(11, JohnCards.At(&JudyCards, 1));
  ASSERT_EQUAL(12, JohnCards.At(&JudyCards, 2));
  ASSERT_EQUAL(13, JohnCards.At(&JudyCards, 3));
  ASSERT_EQUAL(14, JohnCards.At(&JudyCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanielleCards.Size(&DanielleCards));
  ASSERT_EQUAL(15, JohnCards.At(&DanielleCards, 0));
  ASSERT_EQUAL(16, JohnCards.At(&DanielleCards, 1));
  ASSERT_EQUAL(17, JohnCards.At(&DanielleCards, 2));
  ASSERT_EQUAL(18, JohnCards.At(&DanielleCards, 3));
  ASSERT_EQUAL(19, JohnCards.At(&DanielleCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, NicholasCards.Size(&NicholasCards));
  ASSERT_EQUAL(20, JohnCards.At(&NicholasCards, 0));
  ASSERT_EQUAL(21, JohnCards.At(&NicholasCards, 1));
  ASSERT_EQUAL(22, JohnCards.At(&NicholasCards, 2));
  ASSERT_EQUAL(23, JohnCards.At(&NicholasCards, 3));
  ASSERT_EQUAL(24, JohnCards.At(&NicholasCards, 4));
  JohnCards.Destroy(&JohnCards);
  DanCards.Destroy(&DanCards);
  JudyCards.Destroy(&JudyCards);
  DanielleCards.Destroy(&DanielleCards);
  NicholasCards.Destroy(&NicholasCards);
  GameContext.Destroy(&GameContext);
}

CTEST2(DeckOfCards, DealDeckNotShuffledLastPlayerStart) {
  struct Context GameContext = NewContext(data->NotShuffled_, Nicholas);
  ASSERT_EQUAL(NoError, GameContext.Errors_);
  struct CardCollection JohnCards = GameContext.GetPlayersCopyOfCards(&GameContext, John);
  struct CardCollection DanCards = GameContext.GetPlayersCopyOfCards(&GameContext, Dan);
  struct CardCollection JudyCards = GameContext.GetPlayersCopyOfCards(&GameContext, Judy);
  struct CardCollection DanielleCards = GameContext.GetPlayersCopyOfCards(&GameContext, Danielle);
  struct CardCollection NicholasCards = GameContext.GetPlayersCopyOfCards(&GameContext, Nicholas);
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JohnCards.Size(&JohnCards));
  ASSERT_EQUAL(5, JohnCards.At(&JohnCards, 0));
  ASSERT_EQUAL(6, JohnCards.At(&JohnCards, 1));
  ASSERT_EQUAL(7, JohnCards.At(&JohnCards, 2));
  ASSERT_EQUAL(8, JohnCards.At(&JohnCards, 3));
  ASSERT_EQUAL(9, JohnCards.At(&JohnCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanCards.Size(&DanCards));
  ASSERT_EQUAL(10, JohnCards.At(&DanCards, 0));
  ASSERT_EQUAL(11, JohnCards.At(&DanCards, 1));
  ASSERT_EQUAL(12, JohnCards.At(&DanCards, 2));
  ASSERT_EQUAL(13, JohnCards.At(&DanCards, 3));
  ASSERT_EQUAL(14, JohnCards.At(&DanCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JudyCards.Size(&JudyCards));
  ASSERT_EQUAL(15, JohnCards.At(&JudyCards, 0));
  ASSERT_EQUAL(16, JohnCards.At(&JudyCards, 1));
  ASSERT_EQUAL(17, JohnCards.At(&JudyCards, 2));
  ASSERT_EQUAL(18, JohnCards.At(&JudyCards, 3));
  ASSERT_EQUAL(19, JohnCards.At(&JudyCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanielleCards.Size(&DanielleCards));
  ASSERT_EQUAL(20, JohnCards.At(&DanielleCards, 0));
  ASSERT_EQUAL(21, JohnCards.At(&DanielleCards, 1));
  ASSERT_EQUAL(22, JohnCards.At(&DanielleCards, 2));
  ASSERT_EQUAL(23, JohnCards.At(&DanielleCards, 3));
  ASSERT_EQUAL(24, JohnCards.At(&DanielleCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, NicholasCards.Size(&NicholasCards));
  ASSERT_EQUAL(0, JohnCards.At(&NicholasCards, 0));
  ASSERT_EQUAL(1, JohnCards.At(&NicholasCards, 1));
  ASSERT_EQUAL(2, JohnCards.At(&NicholasCards, 2));
  ASSERT_EQUAL(3, JohnCards.At(&NicholasCards, 3));
  ASSERT_EQUAL(4, JohnCards.At(&NicholasCards, 4));
  JohnCards.Destroy(&JohnCards);
  DanCards.Destroy(&DanCards);
  JudyCards.Destroy(&JudyCards);
  DanielleCards.Destroy(&DanielleCards);
  NicholasCards.Destroy(&NicholasCards);
  GameContext.Destroy(&GameContext);
}

CTEST2(DeckOfCards, DealDeckShuffledFirstPlayerStart) {
  struct Context GameContext = NewContext(data->Shuffled_, John);
  ASSERT_EQUAL(NoError, GameContext.Errors_);
  struct CardCollection JohnCards = GameContext.GetPlayersCopyOfCards(&GameContext, John);
  struct CardCollection DanCards = GameContext.GetPlayersCopyOfCards(&GameContext, Dan);
  struct CardCollection JudyCards = GameContext.GetPlayersCopyOfCards(&GameContext, Judy);
  struct CardCollection DanielleCards = GameContext.GetPlayersCopyOfCards(&GameContext, Danielle);
  struct CardCollection NicholasCards = GameContext.GetPlayersCopyOfCards(&GameContext, Nicholas);
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JohnCards.Size(&JohnCards));
  ASSERT_EQUAL(4, JohnCards.At(&JohnCards, 0)); //4, 9, 30, 39, 41
  ASSERT_EQUAL(9, JohnCards.At(&JohnCards, 1));
  ASSERT_EQUAL(30, JohnCards.At(&JohnCards, 2));
  ASSERT_EQUAL(39, JohnCards.At(&JohnCards, 3));
  ASSERT_EQUAL(41, JohnCards.At(&JohnCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanCards.Size(&DanCards));
  ASSERT_EQUAL(5, JohnCards.At(&DanCards, 0)); //5, 7, 8, 13, 33
  ASSERT_EQUAL(7, JohnCards.At(&DanCards, 1));
  ASSERT_EQUAL(8, JohnCards.At(&DanCards, 2));
  ASSERT_EQUAL(13, JohnCards.At(&DanCards, 3));
  ASSERT_EQUAL(33, JohnCards.At(&DanCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JudyCards.Size(&JudyCards));
  ASSERT_EQUAL(3, JohnCards.At(&JudyCards, 0)); //3, 11, 12, 6, 14
  ASSERT_EQUAL(6, JohnCards.At(&JudyCards, 1));
  ASSERT_EQUAL(11, JohnCards.At(&JudyCards, 2));
  ASSERT_EQUAL(12, JohnCards.At(&JudyCards, 3));
  ASSERT_EQUAL(14, JohnCards.At(&JudyCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanielleCards.Size(&DanielleCards));
  ASSERT_EQUAL(18, JohnCards.At(&DanielleCards, 0)); //50, 26, 46, 18, 51
  ASSERT_EQUAL(26, JohnCards.At(&DanielleCards, 1));
  ASSERT_EQUAL(46, JohnCards.At(&DanielleCards, 2));
  ASSERT_EQUAL(50, JohnCards.At(&DanielleCards, 3));
  ASSERT_EQUAL(51, JohnCards.At(&DanielleCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, NicholasCards.Size(&NicholasCards));
  ASSERT_EQUAL(20, JohnCards.At(&NicholasCards, 0)); //20, 29, 22, 23, 24
  ASSERT_EQUAL(22, JohnCards.At(&NicholasCards, 1));
  ASSERT_EQUAL(23, JohnCards.At(&NicholasCards, 2));
  ASSERT_EQUAL(24, JohnCards.At(&NicholasCards, 3));
  ASSERT_EQUAL(29, JohnCards.At(&NicholasCards, 4));
  JohnCards.Destroy(&JohnCards);
  DanCards.Destroy(&DanCards);
  JudyCards.Destroy(&JudyCards);
  DanielleCards.Destroy(&DanielleCards);
  NicholasCards.Destroy(&NicholasCards);
  GameContext.Destroy(&GameContext);
}

CTEST2(DeckOfCards, DealDeckShuffledLastPlayerStart) {
  struct Context GameContext = NewContext(data->Shuffled_, Nicholas);
  ASSERT_EQUAL(NoError, GameContext.Errors_);
  struct CardCollection JohnCards = GameContext.GetPlayersCopyOfCards(&GameContext, John);
  struct CardCollection DanCards = GameContext.GetPlayersCopyOfCards(&GameContext, Dan);
  struct CardCollection JudyCards = GameContext.GetPlayersCopyOfCards(&GameContext, Judy);
  struct CardCollection DanielleCards = GameContext.GetPlayersCopyOfCards(&GameContext, Danielle);
  struct CardCollection NicholasCards = GameContext.GetPlayersCopyOfCards(&GameContext, Nicholas);
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JohnCards.Size(&JohnCards));
  ASSERT_EQUAL(5, JohnCards.At(&JohnCards, 0)); //5, 13, 7, 8, 33
  ASSERT_EQUAL(7, JohnCards.At(&JohnCards, 1));
  ASSERT_EQUAL(8, JohnCards.At(&JohnCards, 2));
  ASSERT_EQUAL(13, JohnCards.At(&JohnCards, 3));
  ASSERT_EQUAL(33, JohnCards.At(&JohnCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanCards.Size(&DanCards));
  ASSERT_EQUAL(3, JohnCards.At(&DanCards, 0)); //3, 11, 12, 6, 14
  ASSERT_EQUAL(6, JohnCards.At(&DanCards, 1));
  ASSERT_EQUAL(11, JohnCards.At(&DanCards, 2));
  ASSERT_EQUAL(12, JohnCards.At(&DanCards, 3));
  ASSERT_EQUAL(14, JohnCards.At(&DanCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JudyCards.Size(&JudyCards));
  ASSERT_EQUAL(18, JohnCards.At(&JudyCards, 0)); //50, 26, 46, 18, 51
  ASSERT_EQUAL(26, JohnCards.At(&JudyCards, 1));
  ASSERT_EQUAL(46, JohnCards.At(&JudyCards, 2));
  ASSERT_EQUAL(50, JohnCards.At(&JudyCards, 3));
  ASSERT_EQUAL(51, JohnCards.At(&JudyCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanielleCards.Size(&DanielleCards));
  ASSERT_EQUAL(20, JohnCards.At(&DanielleCards, 0)); //20, 29, 22, 23, 24
  ASSERT_EQUAL(22, JohnCards.At(&DanielleCards, 1));
  ASSERT_EQUAL(23, JohnCards.At(&DanielleCards, 2));
  ASSERT_EQUAL(24, JohnCards.At(&DanielleCards, 3));
  ASSERT_EQUAL(29, JohnCards.At(&DanielleCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, NicholasCards.Size(&NicholasCards));
  ASSERT_EQUAL(4, JohnCards.At(&NicholasCards, 0)); //9, 41, 39, 30, 4
  ASSERT_EQUAL(9, JohnCards.At(&NicholasCards, 1));
  ASSERT_EQUAL(30, JohnCards.At(&NicholasCards, 2));
  ASSERT_EQUAL(39, JohnCards.At(&NicholasCards, 3));
  ASSERT_EQUAL(41, JohnCards.At(&NicholasCards, 4));
  JohnCards.Destroy(&JohnCards);
  DanCards.Destroy(&DanCards);
  JudyCards.Destroy(&JudyCards);
  DanielleCards.Destroy(&DanielleCards);
  NicholasCards.Destroy(&NicholasCards);
  GameContext.Destroy(&GameContext);
}

CTEST2(DeckOfCards, SinglePlayWithUnshuffledDeck) {
  struct Context GameContext = NewContext(data->NotShuffled_, John);
  ASSERT_EQUAL(NoError, GameContext.Errors_);
  struct PlayerInput AskForKingOfSpades;
  AskForKingOfSpades.RequestedCard_ = 51;
  AskForKingOfSpades.ThisPlayer_ = John;
  AskForKingOfSpades.PlayerToRequestCardOf_ = Dan;
  struct PlayerOutput Output = GameContext.Play(&GameContext, &AskForKingOfSpades);
  GameContext.Destroy(&GameContext);
}

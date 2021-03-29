#include "ctest.h"
#include "ExternalSymbols.h"

/*
          ACE   2   3   4   5   6   7   8   9   10   J   Q   K
Clubs     0     4   8   12  16  20  24  28  32  36   40  44  48
Diamonds  1     5   9   13  17  21  25  29  33  37   41  45  49
Hearts    2     6   10  14  18  22  26  30  34  38   42  46  50
Spades    3     7   11  15  19  23  27  31  35  39   43  47  51
*/

CTEST(DealTests, DealDeckNotShuffledFirstPlayerStart) {
  Card CardsInDeck[52] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 25, 36, 37, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 59, 51
  };
  struct Context GameContext = NewContext(&CardsInDeck, John);
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

CTEST(DealTests, DealDeckNotShuffledLastPlayerStart) {
  Card CardsInDeck[52] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 25, 36, 37, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 59, 51
  };
  struct Context GameContext = NewContext(&CardsInDeck, Nicholas);
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

CTEST(DealTests, DealDeckShuffledFirstPlayerStart) {
  Card CardsInDeck[52] = {
    7, 1, 4, 3, 23, 5, 6, 0, 8, 37,
    20, 11, 12, 13, 34, 15, 16, 17, 18, 41,
    10, 51, 22, 2, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 14, 25, 36, 9, 39, 40,
    19, 42, 43, 44, 45, 46, 47, 48, 59, 21
  };
  struct Context GameContext = NewContext(&CardsInDeck, John);
  struct CardCollection JohnCards = GameContext.GetPlayersCopyOfCards(&GameContext, John);
  struct CardCollection DanCards = GameContext.GetPlayersCopyOfCards(&GameContext, Dan);
  struct CardCollection JudyCards = GameContext.GetPlayersCopyOfCards(&GameContext, Judy);
  struct CardCollection DanielleCards = GameContext.GetPlayersCopyOfCards(&GameContext, Danielle);
  struct CardCollection NicholasCards = GameContext.GetPlayersCopyOfCards(&GameContext, Nicholas);
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JohnCards.Size(&JohnCards));
  ASSERT_EQUAL(1, JohnCards.At(&JohnCards, 0));
  ASSERT_EQUAL(3, JohnCards.At(&JohnCards, 1));
  ASSERT_EQUAL(4, JohnCards.At(&JohnCards, 2));
  ASSERT_EQUAL(7, JohnCards.At(&JohnCards, 3));
  ASSERT_EQUAL(23, JohnCards.At(&JohnCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanCards.Size(&DanCards));
  ASSERT_EQUAL(0, JohnCards.At(&DanCards, 0));
  ASSERT_EQUAL(5, JohnCards.At(&DanCards, 1));
  ASSERT_EQUAL(6, JohnCards.At(&DanCards, 2));
  ASSERT_EQUAL(8, JohnCards.At(&DanCards, 3));
  ASSERT_EQUAL(37, JohnCards.At(&DanCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JudyCards.Size(&JudyCards));
  ASSERT_EQUAL(11, JohnCards.At(&JudyCards, 0));
  ASSERT_EQUAL(12, JohnCards.At(&JudyCards, 1));
  ASSERT_EQUAL(13, JohnCards.At(&JudyCards, 2));
  ASSERT_EQUAL(20, JohnCards.At(&JudyCards, 3));
  ASSERT_EQUAL(34, JohnCards.At(&JudyCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanielleCards.Size(&DanielleCards));
  ASSERT_EQUAL(15, JohnCards.At(&DanielleCards, 0));
  ASSERT_EQUAL(16, JohnCards.At(&DanielleCards, 1));
  ASSERT_EQUAL(17, JohnCards.At(&DanielleCards, 2));
  ASSERT_EQUAL(18, JohnCards.At(&DanielleCards, 3));
  ASSERT_EQUAL(41, JohnCards.At(&DanielleCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, NicholasCards.Size(&NicholasCards));
  ASSERT_EQUAL(2, JohnCards.At(&NicholasCards, 0));
  ASSERT_EQUAL(10, JohnCards.At(&NicholasCards, 1));
  ASSERT_EQUAL(22, JohnCards.At(&NicholasCards, 2));
  ASSERT_EQUAL(24, JohnCards.At(&NicholasCards, 3));
  ASSERT_EQUAL(51, JohnCards.At(&NicholasCards, 4));
  JohnCards.Destroy(&JohnCards);
  DanCards.Destroy(&DanCards);
  JudyCards.Destroy(&JudyCards);
  DanielleCards.Destroy(&DanielleCards);
  NicholasCards.Destroy(&NicholasCards);
  GameContext.Destroy(&GameContext);
}

CTEST(DealTests, DealDeckShuffledLastPlayerStart) {
  Card CardsInDeck[52] = {
    7, 1, 4, 3, 23, 5, 6, 0, 8, 37,
    20, 11, 12, 13, 34, 15, 16, 17, 18, 41,
    10, 51, 22, 2, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 14, 25, 36, 9, 39, 40,
    19, 42, 43, 44, 45, 46, 47, 48, 59, 21
  };
  struct Context GameContext = NewContext(&CardsInDeck, Nicholas);
  struct CardCollection JohnCards = GameContext.GetPlayersCopyOfCards(&GameContext, John);
  struct CardCollection DanCards = GameContext.GetPlayersCopyOfCards(&GameContext, Dan);
  struct CardCollection JudyCards = GameContext.GetPlayersCopyOfCards(&GameContext, Judy);
  struct CardCollection DanielleCards = GameContext.GetPlayersCopyOfCards(&GameContext, Danielle);
  struct CardCollection NicholasCards = GameContext.GetPlayersCopyOfCards(&GameContext, Nicholas);
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JohnCards.Size(&JohnCards));
  ASSERT_EQUAL(0, JohnCards.At(&JohnCards, 0)); //5, 6, 0, 8, 37
  ASSERT_EQUAL(5, JohnCards.At(&JohnCards, 1));
  ASSERT_EQUAL(6, JohnCards.At(&JohnCards, 2));
  ASSERT_EQUAL(8, JohnCards.At(&JohnCards, 3));
  ASSERT_EQUAL(37, JohnCards.At(&JohnCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanCards.Size(&DanCards));
  ASSERT_EQUAL(11, JohnCards.At(&DanCards, 0)); //20, 11, 12, 13, 34
  ASSERT_EQUAL(12, JohnCards.At(&DanCards, 1));
  ASSERT_EQUAL(13, JohnCards.At(&DanCards, 2));
  ASSERT_EQUAL(20, JohnCards.At(&DanCards, 3));
  ASSERT_EQUAL(34, JohnCards.At(&DanCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JudyCards.Size(&JudyCards));
  ASSERT_EQUAL(15, JohnCards.At(&JudyCards, 0)); //15, 16, 17, 18, 41
  ASSERT_EQUAL(16, JohnCards.At(&JudyCards, 1));
  ASSERT_EQUAL(17, JohnCards.At(&JudyCards, 2));
  ASSERT_EQUAL(18, JohnCards.At(&JudyCards, 3));
  ASSERT_EQUAL(41, JohnCards.At(&JudyCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanielleCards.Size(&DanielleCards));
  ASSERT_EQUAL(2, JohnCards.At(&DanielleCards, 0)); //10, 51, 22, 2, 24
  ASSERT_EQUAL(10, JohnCards.At(&DanielleCards, 1));
  ASSERT_EQUAL(22, JohnCards.At(&DanielleCards, 2));
  ASSERT_EQUAL(24, JohnCards.At(&DanielleCards, 3));
  ASSERT_EQUAL(51, JohnCards.At(&DanielleCards, 4));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, NicholasCards.Size(&NicholasCards));
  ASSERT_EQUAL(1, JohnCards.At(&NicholasCards, 0)); //7, 1, 4, 3, 23
  ASSERT_EQUAL(3, JohnCards.At(&NicholasCards, 1));
  ASSERT_EQUAL(4, JohnCards.At(&NicholasCards, 2));
  ASSERT_EQUAL(7, JohnCards.At(&NicholasCards, 3));
  ASSERT_EQUAL(23, JohnCards.At(&NicholasCards, 4));
  JohnCards.Destroy(&JohnCards);
  DanCards.Destroy(&DanCards);
  JudyCards.Destroy(&JudyCards);
  DanielleCards.Destroy(&DanielleCards);
  NicholasCards.Destroy(&NicholasCards);
  GameContext.Destroy(&GameContext);
}

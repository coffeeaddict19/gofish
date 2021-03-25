#include "ctest.h"
#include "ExternalSymbols.h"

/*
          ACE   2   3   4   5   6   7   8   9   10   J   Q   K
Clubs     0     4   8   12  16  20  24  28  32  36   40  44  48
Diamonds  1     5   9   13  17  21  25  29  33  37   41  45  49
Hearts    2     6   10  14  18  22  26  30  34  38   42  46  50
Spades    3     7   11  15  19  23  27  31  35  39   43  47  51
*/

CTEST(DealTests, CheckCorrectDealCount) {
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
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanCards.Size(&DanCards));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, JudyCards.Size(&JudyCards));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, DanielleCards.Size(&DanielleCards));
  ASSERT_EQUAL(kNumberOfCardsToDealPerPlayer, NicholasCards.Size(&NicholasCards));
  JohnCards.Destroy(&JohnCards);
  DanCards.Destroy(&DanCards);
  JudyCards.Destroy(&JudyCards);
  DanielleCards.Destroy(&DanielleCards);
  NicholasCards.Destroy(&NicholasCards);
  GameContext.Destroy(&GameContext);
}

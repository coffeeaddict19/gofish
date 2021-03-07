#ifndef CPPCOMMON_H
#define CPPCOMMON_H

#include <cstddef>
#include <array>
#include <memory>
#include "Card.h"

const size_t kNumberOfCardsInDeck = 52;
const size_t kNumberOfCardsInBook = 4;
using CardPtrType = std::unique_ptr<Card>;
using PoolOfCardsType = std::array<CardPtrType,kNumberOfCardsInDeck>;

#endif

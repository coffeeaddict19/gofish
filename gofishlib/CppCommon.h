#ifndef CPPCOMMON_H
#define CPPCOMMON_H

#include <array>
#include <memory>
#include <vector>
#include "CCommon.h"

using CardPtrType = std::unique_ptr<Card>;
using PoolOfCardsType = std::array<CardPtrType,kNumberOfCardsInDeck>;
using CardCollectionInternalType = std::vector<Card>;

#endif

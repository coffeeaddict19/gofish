#ifndef BASECARDPOOL_H
#define BASECARDPOOL_H

#include <array>
#include <memory>
#include "Card.h"
#include "CppCommon.h"

class BaseCardPool{
protected:
  BaseCardPool();
  BaseCardPool(const BaseCardPool&) = delete;
  ~BaseCardPool();
  bool IsFull();
  bool IsEmpty();
  PoolOfCardsType Pool_;
};

#endif

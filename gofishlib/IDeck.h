#ifndef IDECK_H
#define IDECK_H

#include "BaseCardPool.h"

class IDeck : protected BaseCardPool{
public:
  virtual CardPtrType Draw() = 0;
};

#endif

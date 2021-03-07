#ifndef IDECK_H
#define IDECK_H

#include "CppCommon.h"

class IDeck{
public:
  virtual CardPtrType Draw() = 0;
};

#endif

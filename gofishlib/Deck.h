#ifndef DECK_H
#define DECK_H

#include "Logger.h"
#include "IDeck.h"

class Deck : public IDeck{
public:
  Deck(Logger* Logger);
  CardPtrType Draw();
private:
  unsigned char CardIndex_;
  Logger* Logger_;
};

#endif

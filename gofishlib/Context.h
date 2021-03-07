#ifndef CONTEXTTYPES_H
#define CONTEXTTYPES_H

#include "Card.h"
#include "CCommon.h"
#include "Logger.h"

typedef void* GamePtr;

struct HumanPlayerTurnInputs{
    Card RequestedCard_;
    ePlayers AIPlayerToRequestCardOf_;
};

struct HumanPlayerTurnOutputs{
    bool Win_;
    bool YouGetAnotherTurn_;
    CardCollectionWithInitFlag GoFishCards_;
    eErrors Error_;
};

struct AIPlayerTurnOutputs{
    bool Win_;
    bool AIGetsAnotherTurn_;
    ePlayers CurrentAIPlayer_;
    CardCollectionWithInitFlag GoFishCards_;
    eErrors Error_;
};

struct Context{
    GamePtr GamePtr_;
    Logger* Logger_;
    void (*SetLogger)(Context* PtrToContext, Logger* PtrToLogger);
    void (*Destroy)(Context* PtrToContext);
    bool (*IsGameOver)(Context* PtrToContext);
    HumanPlayerTurnOutputs (*PlayHumanTurn)(Context* PtrToContext, HumanPlayerTurnInputs* RequestedCard);
    CardCollectionWithInitFlag (*GetHumanCards)(Context* PtrToContext);
    AIPlayerTurnOutputs (*PlayAITurn)(Context* PtrToContext);
};

#endif

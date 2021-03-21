#ifndef EXTERNALSYMBOLS_H
#define EXTERNALSYMBOLS_H

#include "CCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Context NewContext(Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck], enum ePlayers FirstPlayer)
__attribute__ ((visibility ("default") ));

struct Logger NewConsoleLogger()
__attribute__ ((visibility ("default") ));

#ifdef __cplusplus
}
#endif

#endif

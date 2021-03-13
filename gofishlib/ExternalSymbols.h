#ifndef EXTERNALSYMBOLS_H
#define EXTERNALSYMBOLS_H

#include "CCommon.h"

#ifdef __cplusplus
extern "C" {
#endif

Context NewContext() __attribute__ ((visibility ("default") ));
Logger NewConsoleLogger() __attribute__ ((visibility ("default") ));

#ifdef __cplusplus
}
#endif

#endif

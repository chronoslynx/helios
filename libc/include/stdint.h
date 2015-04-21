#ifndef HELIOS_STDINT_H
#define HELIOS_STDINT_H 1

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif
    typedef char int8_t;
    typedef unsigned char uint8_t;
    typedef short int16_t;
    typedef unsigned short uint16_t;
    typedef unsigned int uint32_t;
    typedef long long int64_t;
    typedef unsigned long long uint64_t;
#ifdef __cplusplus
}
#endif
#endif

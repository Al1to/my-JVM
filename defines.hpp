#pragma once

#include <iostream>

#ifdef DEBUG
    #define DBG(x) std::cout << x << "\n";
#else
    #define DBG(x) 
#endif

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
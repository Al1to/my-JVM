#pragma once

#include <iostream>
#include <iomanip>
#include <cstdint>

#include "../../defines.hpp"

#include <vector>
 
class MEM {
    private:
        std::vector<u8> mem;
        u32 prgc = 0;

    public:
        MEM(unsigned int size) { mem.resize(size, 0); }

        void write(unsigned int index, u8 value);

        u8 read(unsigned int index);

        unsigned int mem_len();

        void set_prgc(u32 value);

        u32 get_prgc();

        u8 fetch8();

        u16 fetch16();

        u32 fetch32();

        u64 fetch64();

        void dbg_log_mem();
};

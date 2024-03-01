#pragma once

#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>

#include "../../defines.hpp"
#include "./mem.hpp"

enum status {
    ok,
    err,
    warn
};

struct cont {
    u32 index;
    u32 buffer;
};

class CPU {
    private:
        MEM &mem;
        std::unordered_map<u8, std::function<void()>> instrs_map;
    
        u32 ldc_buffer = 0;
        std::vector<cont> conts_stack;

        void ldc_0x21();
        void iload_0x22();
        void istore_0x23();

    public:
        CPU(MEM &mem) : mem(mem) {
            instrs_map = {
                {0x21, [this]() { ldc_0x21(); }},
                {0x22, [this]() { iload_0x22(); }},
                {0x23, [this]() { istore_0x23(); }},
            };
        }

        status exec(u8 opcode);
};
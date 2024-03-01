#pragma once

#include "../headers/cpu.hpp"

void CPU::ldc_0x21() {
    DBG("ldc");
    u32 lit = mem.fetch32();
    ldc_buffer = lit;
}

void CPU::iload_0x22() {
    DBG("iload");
    cont container;

    container.index = mem.fetch32();
    container.buffer = ldc_buffer;

    conts_stack.push_back(container);
}

void CPU::istore_0x23() {

}

status CPU::exec(u8 opcode) {
    if (opcode == 0x00) return status::err;

    auto it = instrs_map.find(opcode);
    if (it != instrs_map.end()) {
        it->second();
        return status::ok;
    } else {
        return status::err;
    }
}

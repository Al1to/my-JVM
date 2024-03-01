#include "../headers/mem.hpp"

void MEM::write(unsigned int index, u8 value) {
    mem[index] = value;
}

u8 MEM::read(unsigned int index) {
    return mem[index];
}

unsigned int MEM::mem_len() {
    return mem.size();
}

void MEM::set_prgc(u32 value) {
    prgc = value;
}

u32 MEM::get_prgc() {
    return prgc;
}

u8 MEM::fetch8() {
    u32 prgc = get_prgc();
    u8 value = mem[prgc];
    set_prgc(prgc + 1);
    return value;
}
        
u16 MEM::fetch16() {
    u32 prgc = get_prgc();

    u16 value = mem[prgc + 1] 
    | (mem[prgc] << 8);

    set_prgc(prgc + 2);
    return value;
}

u32 MEM::fetch32() {
    u32 prgc = get_prgc();

    u32 value = mem[prgc + 3] 
    | (mem[prgc + 2] << 8)
    | (mem[prgc + 1] << 16)
    | (mem[prgc] << 24);

    set_prgc(prgc + 4);
    return value;
}

u64 MEM::fetch64() {
    u32 prgc = get_prgc();

    u64 value = mem[prgc + 7] 
    | (mem[prgc + 6] << 8) 
    | (mem[prgc + 5] << 16) 
    | (mem[prgc + 4] << 24) 
    | (mem[prgc + 3] << 32) 
    | (mem[prgc + 2] << 40) 
    | (mem[prgc + 1] << 48) 
    | (mem[prgc] << 56);

    set_prgc(prgc + 8);
    return value;
}

void MEM::dbg_log_mem() {
    int count = 0;
    for (u8 i : mem) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(i) << " ";
        ++count;
        if (count == 32) {
            std::cout << "\n";
            count = 0;
        }
    }
    if (count != 0) {
        std::cout << "\n";
    }
    std::cout << "\n";
}
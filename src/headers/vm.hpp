#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include "./cpu.hpp"
#include "./mem.hpp"

class VM {
    public:
        VM(unsigned int &mem_size, std::string &code) : mem(mem_size), cpu(mem), code(code) {}

        void run() {
            mem.write(0, 0x21);
            mem.write(1, 0x01);
            mem.write(2, 0x02);
            mem.write(3, 0x03);
            mem.write(4, 0x04);

            mem.dbg_log_mem();
            
            while (mem.get_prgc() < mem.mem_len()) {
                status is_ok = cpu.exec(mem.fetch8());
                if (is_ok != status::ok) break;
            }
        }

    private:
        CPU cpu;
        MEM mem;
        std::string &code;
};
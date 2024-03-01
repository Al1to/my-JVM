#include "./src/headers/vm.hpp"

#include <string>

#include "./defines.hpp"

int main(int argc, char* argv[]) {
    unsigned int mem_size = 256;
    std::string code = "";
    VM vm(mem_size, code);
    vm.run();
    return 0;
}
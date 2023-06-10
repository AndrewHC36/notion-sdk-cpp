#include "../src/api_entrypoints.hpp"

#include <iostream>

int test_prelude(int argc, char** const argv) {
    int num = double_it(4);

    std::cout << num << std::endl;

    return 0;
}

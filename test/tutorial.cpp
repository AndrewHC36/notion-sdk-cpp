#include "../src/api_entrypoints.hpp"

#include <iostream>

int main() {
    int num = double_it(4);

    std::cout << num << std::endl;

    return 0;
}

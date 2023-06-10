#include "client.hpp"

#include <cpr/cpr.h>

DLLExport int double_it(int num) {
    return num+num;
}

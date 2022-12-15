#include <iostream>

#include "bools.h"

bool_string str {
    { false, true, false, false, true, false, false, false },
    { false, true, true, false, false, true, false, true },
    { false, true, true, false, true, true, false, false },
    { false, true, true, false, true, true, false, false },
    { false, true, true, false, true, true, true, true },
    { false, false, true, false, true, true, false, false },
    { false, false, true, false, false, false, false, false },
    { false, true, false, true, false, true, true, true },
    { false, true, true, false, true, true, true, true },
    { false, true, true, true, false, false, true, false },
    { false, true, true, false, true, true, false, false },
    { false, true, true, false, false, true, false, false },
    { false, false, true, false, false, false, false, true },
    { false, false, true, false, false, false, false, false },
    { false, true, false, true, false, true, false, false },
    { false, true, true, false, true, false, false, false },
    { false, true, true, false, true, false, false, true },
    { false, true, true, true, false, false, true, true },
    { false, false, true, false, false, false, false, false },
    { false, true, true, false, true, false, false, true },
    { false, true, true, true, false, false, true, true },
    { false, false, true, false, false, false, false, false },
    { false, true, true, false, false, false, false, true },
    { false, false, true, false, false, false, false, false },
    { false, true, true, true, false, true, false, false },
    { false, true, true, false, false, true, false, true },
    { false, true, true, true, false, false, true, true },
    { false, true, true, true, false, true, false, false },
    { false, false, true, false, false, false, false, false },
    { false, true, true, false, false, true, false, true },
    { false, true, true, true, true, false, false, false },
    { false, true, true, false, false, false, false, true },
    { false, true, true, false, true, true, false, true },
    { false, true, true, true, false, false, false, false },
    { false, true, true, false, true, true, false, false },
    { false, true, true, false, false, true, false, true },
    { false, false, true, false, true, true, true, false }
};

int main() {
    std::cout << str.decode();
}
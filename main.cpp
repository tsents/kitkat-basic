#include "basic_string.h"
#include <iostream>

int main() {
    basicString s = "Hello!";
    s = "Other?"; // Causes memleak
    std::cout << s << basicString() << std::endl;
    return 0;
}

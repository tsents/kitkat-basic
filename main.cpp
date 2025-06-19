#include "basic_string.h"
#include <iostream>

int main() {
    basicString s = "Hello!";
    s = "Other?";
    basicString another_one = "\n";
    std::cout << (s + another_one) << std::endl; // No leaks.
    return 0;
}

#include "basic_string.h"
#include <iostream>

int main() {
    std::cout << (basicString("\n") == basicString("\n")) << std::endl; // Should be true
    std::cout << (basicString("A") >= basicString("\n")) << std::endl;  // Should be true
    std::cout << (basicString("AA") <= basicString("A")) << std::endl;  // Should be false. its strictly greater
    std::cout << (basicString("AA") > basicString("AB")) << std::endl;  // Should be false. its the oppisite.
    return 0;
}

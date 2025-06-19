#include "basic_string.h"
#include <iostream>

int main() {
    basicString s = basicString("Hello!");
    std::cout << s << basicString() << std::endl;
    return 0;
}

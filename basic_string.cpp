#include "basic_string.h"
#include <cstring>
#include <iostream>

//>>>char* Utilities

unsigned int customStrlen(const char* cstring) { // Tested. customStrlen("Hello!") = 6;
    if (cstring == NULL) {
        return 0;
    }
    char running_char = cstring[0];
    unsigned int length = 0;
    while (running_char != '\0') {
        length++;
        running_char = cstring[length];
    }
    return length;
}

void safeStrcpy(char* target, const char* source) {
    if (source == NULL) {
        return;
    }
    if (target == NULL) {
        return;
    }
    std::memcpy(target, source, customStrlen(source));
    target[customStrlen(target) + 1] = '\0';
}

int customStrcmp(const char* lhs, const char* rhs) {
    if (lhs == NULL && rhs == NULL) {
        return 0;
    }
    if (lhs == NULL) {
        return -1; // lhs = rhs - 1. thus lhs is smaller.
    }
    if (rhs == NULL) {
        return 1; // Same as before but >.
    }
    for (unsigned int i = 0;; i++) { // Does this until finds diff. or char '\0'
        if (rhs[i] != lhs[i]) {      // This also catches one string ending but other not.
            return lhs[i] - rhs[i];
        }
        if (rhs[i] == '\0') { // This actually means both strings have ended.
            return 0;
        }
    }
}
//<<<char* Utilities

//>>>Basic Object Utilities
basicString::basicString() : m_char_data(NULL){};

basicString::basicString(const char* char_data) {
    m_char_data = new char[customStrlen(char_data) + 1]; // for the '\0' symbol;
    safeStrcpy(m_char_data, char_data);
};

basicString& basicString::operator=(const char* char_data) {
    if (m_char_data != NULL) {
        delete[] m_char_data;
    }
    m_char_data = new char[customStrlen(char_data) + 1]; // for the '\0' symbol;
    safeStrcpy(m_char_data, char_data);
    return *this;
}

basicString& basicString::operator=(const basicString& other) {
    if (m_char_data != NULL) {
        delete[] m_char_data;
    }
    std::cout << "Print me?" << std::endl;
    *this = other.m_char_data;
    return *this;
}

basicString::~basicString() {
    if (m_char_data != NULL) {
        delete[] m_char_data;
    }
}

std::ostream& operator<<(std::ostream& os, const basicString& obj) {
    return os << obj.m_char_data; // It is allready implemented for char*.
}

//<<<Basic Object Utilities

//>>Additional Operators

basicString operator+(const basicString& lhs, const basicString& rhs) {
    char* new_char_data = new char[customStrlen(lhs.m_char_data) + customStrlen(rhs.m_char_data) + 1];
    safeStrcpy(new_char_data, lhs.m_char_data);
    safeStrcpy(new_char_data + customStrlen(lhs.m_char_data), rhs.m_char_data);

    // Do this trick, to avoid additional new and copying of string.
    basicString new_string = basicString();
    new_string.m_char_data = new_char_data;
    return new_string;
}

basicString operator*(const basicString& base, unsigned int times) {
    unsigned int base_length = customStrlen(base.m_char_data);
    char* new_char_data = new char[base_length * times + 1];
    for (unsigned int i = 0; i < times; i++) {
        safeStrcpy(new_char_data + base_length * i, base.m_char_data);
    }

    // Do this trick, to avoid additional new and copying of string.
    basicString new_string = basicString();
    new_string.m_char_data = new_char_data;
    return new_string;
}

bool operator==(const basicString& lhs, const basicString& rhs) {
    return (customStrcmp(lhs.m_char_data, rhs.m_char_data) == 0);
}

bool operator<(const basicString& lhs, const basicString& rhs) {
    return (customStrcmp(lhs.m_char_data, rhs.m_char_data) < 0);
}

bool operator>(const basicString& lhs, const basicString& rhs) {
    return (customStrcmp(lhs.m_char_data, rhs.m_char_data) > 0);
}

bool operator>=(const basicString& lhs, const basicString& rhs) {
    return (customStrcmp(lhs.m_char_data, rhs.m_char_data) >= 0);
}

bool operator<=(const basicString& lhs, const basicString& rhs) {
    return (customStrcmp(lhs.m_char_data, rhs.m_char_data) <= 0);
}

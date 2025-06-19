#include "basic_string.h"
#include <cstring>
#include <iostream>

basicString::basicString() : m_char_data(new char[0]){};

basicString::basicString(const char* char_data) {
    m_char_data = new char[std::strlen(char_data) + 1]; // for the '\0' symbol;
    strcpy(m_char_data, char_data);
};

basicString& basicString::operator=(const char* char_data) {
    if (m_char_data != NULL) {
        delete[] m_char_data;
    }
    m_char_data = new char[std::strlen(char_data) + 1]; // for the '\0' symbol;
    strcpy(m_char_data, char_data);
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

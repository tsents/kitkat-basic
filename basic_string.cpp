#include "basic_string.h"
#include <cstring>

basicString::basicString() : m_char_data(new char[0]){};

basicString::basicString(const char* char_data) {
    m_char_data = new char[std::strlen(char_data) + 1]; // for the '\0' symbol;
    strcpy(m_char_data, char_data);
};

basicString& basicString::operator=(const char* char_data) {
    if (char_data != NULL) {
        delete[] char_data;
    }
    m_char_data = new char[std::strlen(char_data) + 1]; // for the '\0' symbol;
    strcpy(m_char_data, char_data);
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

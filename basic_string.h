#pragma once

#include <ostream>

/*
 * This class implements a string class, simillar to std::string.
 * it should behave as smooth as basic string! and be invisible to the user.
 */
class basicString {
public:
    basicString();
    basicString(const char*);

    /*
     * This uses basicString(const char*) constructor.
     */
    basicString& operator=(const char*);

    /*
     * Copies using the = operator of const char*. copies the m_char_data as well.
     */
    basicString& operator=(const basicString&);

    /*
     * Deconstructor that frees char_data from the heap.
     */
    ~basicString();

    /*
     * Overloads << to calls << as it will with char*.
     */
    friend std::ostream& operator<<(std::ostream& os, const basicString& obj);

    /*
     * Concatenates two string to create a new string.
     */
    friend basicString operator+(const basicString& lhs, const basicString& rhs);

    /*
     * Returns a string that is the base string repeated (times) times.
     */
    friend basicString operator*(const basicString& base, unsigned int times);

    /**
     * Comparision of strings based on lexigraphic ordering. (wrapping strcmp result).
     */
    friend bool operator==(const basicString& lhs, const basicString& rhs);
    friend bool operator<(const basicString& lhs, const basicString& rhs);
    friend bool operator>(const basicString& lhs, const basicString& rhs);
    friend bool operator>=(const basicString& lhs, const basicString& rhs);
    friend bool operator>=(const basicString& lhs, const basicString& rhs);

private:
    char* m_char_data;
};

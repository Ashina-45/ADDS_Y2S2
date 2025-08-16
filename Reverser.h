#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser {
public:
    // Reverse the digits of a non-negative integer using recursion.
    // Returns -1 on invalid input (e.g., negative).
    int reverseDigit(int value);

    // Reverse a string using recursion.
    // Returns "ERROR" on invalid input (here treated as empty string).
    std::string reverseString(const std::string& characters);

private:
    // Helpers (purely recursive)
    int reverseDigitHelper(int n, int acc);
    std::string reverseStringHelper(const std::string& s, std::size_t idx);
};

#endif // REVERSER_H

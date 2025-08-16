#include "Reverser.h"

// Public API
int Reverser::reverseDigit(int value) {
    if (value < 0) return -1;           // error indicator
    // Special-case 0 so reverseDigit(0) == 0
    return reverseDigitHelper(value, 0);
}

std::string Reverser::reverseString(const std::string& characters) {
    if (characters.empty()) return "ERROR"; // error indicator by spec
    return reverseStringHelper(characters, characters.size());
}

// Private helpers (recursive)
int Reverser::reverseDigitHelper(int n, int acc) {
    // Base case: no digits left
    if (n == 0) return acc;
    // Recur with remaining digits; build reversed value in acc
    return reverseDigitHelper(n / 10, acc * 10 + (n % 10));
}

std::string Reverser::reverseStringHelper(const std::string& s, std::size_t idx) {
    // Base case: consumed all characters
    if (idx == 0) return std::string();
    // Take last char + recurse on the rest
    return std::string(1, s[idx - 1]) + reverseStringHelper(s, idx - 1);
}
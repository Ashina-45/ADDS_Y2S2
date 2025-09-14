#include "BigNumCalc.h"
#include <algorithm>
#include <iostream>

BigNumCalc::BigNumCalc() {}
BigNumCalc::~BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> result;
    for (char c : numString) {
        result.push_back(c - '0');
    }
    return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        if (it1 != num1.rend()) sum += *it1++;
        if (it2 != num2.rend()) sum += *it2++;
        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int borrow = 0;

    while (it1 != num1.rend()) {
        int diff = *it1 - borrow;
        if (it2 != num2.rend()) diff -= *it2++;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else borrow = 0;
        result.push_front(diff);
        ++it1;
    }

    while (!result.empty() && result.front() == 0 && result.size() > 1) {
        result.pop_front();
    }
    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    int multiplier = num2.back(); // assume single digit
    std::list<int> result;
    int carry = 0;

    auto it1 = num1.rbegin();
    while (it1 != num1.rend() || carry) {
        int prod = carry;
        if (it1 != num1.rend()) prod += (*it1++) * multiplier;
        result.push_front(prod % 10);
        carry = prod / 10;
    }

    while (!result.empty() && result.front() == 0 && result.size() > 1) {
        result.pop_front();
    }
    return result;
}

#include "Human.h"
#include "moveCreate.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

Human::Human(std::string name) : name_(std::move(name)) {}

std::string Human::getName() const { return name_; }

static std::string trim(std::string s) {
    auto notspace = [](unsigned char c){ return !std::isspace(c); };
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), notspace));
    s.erase(std::find_if(s.rbegin(), s.rend(), notspace).base(), s.end());
    return s;
}

Move* Human::makeMove() {
    std::string in;
    std::cout << "Enter Move (Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zombie): ";
    std::getline(std::cin, in);
    in = trim(in);
    // Spec says invalid behaviour is undefined; return nullptr if not a valid move.
    return createMoveFromName(in);
}

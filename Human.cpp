#include "Human.h"
#include "MoveFactory.h"
#include <iostream>

Human::Human(const std::string& name) : name(name) {}

Move* Human::makeMove() {
    std::string moveName;
    std::cout << "Enter Move: ";
    std::cin >> moveName;
    return createMoveFromName(moveName);
}

std::string Human::getName() const {
    return name;
}
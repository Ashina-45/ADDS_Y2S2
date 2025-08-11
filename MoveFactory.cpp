#include "MoveFactory.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Robot.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

std::unique_ptr<Move> createMoveFromName(const std::string& moveName) {
    if (moveName == "Rock") {
        return std::make_unique<Rock>();
    } else if (moveName == "Paper") {
        return std::make_unique<Paper>();
    } else if (moveName == "Scissors") {
        return std::make_unique<Scissors>();
    } else if (moveName == "Robot") {
        return std::make_unique<Robot>();
    } else if (moveName == "Monkey") {
        return std::make_unique<Monkey>();
    } else if (moveName == "Pirate") {
        return std::make_unique<Pirate>();
    } else if (moveName == "Ninja") {
        return std::make_unique<Ninja>();
    } else if (moveName == "Zombie") {
        return std::make_unique<Zombie>();
    } else {
        return nullptr;
    }
}

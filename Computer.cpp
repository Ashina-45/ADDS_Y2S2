#include "Computer.h"
#include "moveCreate.h"
#include <chrono>
#include <random>

Computer::Computer(std::string name)
    : name_(std::move(name)),
      choices_({"Rock","Paper","Scissors","Robot","Monkey","Pirate","Ninja","Zombie"}) {}

std::string Computer::getName() const { return name_; }

void Computer::setChoices(std::vector<std::string> choices) {
    if (!choices.empty()) choices_ = std::move(choices);
}

Move* Computer::makeMove() {
    static std::mt19937 rng(
        static_cast<unsigned int>(
            std::chrono::high_resolution_clock::now().time_since_epoch().count()
        )
    );
    std::uniform_int_distribution<std::size_t> dist(0, choices_.size() - 1);
    const std::string& pick = choices_[dist(rng)];
    return createMoveFromName(pick);
}

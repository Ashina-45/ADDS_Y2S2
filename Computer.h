#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <string>
#include <vector>

class Computer : public Player {
public:
    explicit Computer(std::string name = "Computer");
    Move* makeMove() override;
    std::string getName() const override;

    // Optional: restrict the computer to a subset of moves
    void setChoices(std::vector<std::string> choices);

private:
    std::string name_;
    std::vector<std::string> choices_;
};

#endif

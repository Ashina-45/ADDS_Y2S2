#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <string>

class Human : public Player {
public:
    explicit Human(std::string name = "Human");
    Move* makeMove() override;
    std::string getName() const override;

private:
    std::string name_;
};

#endif

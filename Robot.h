#ifndef ROBOT_H
#define ROBOT_H

#include "Move.h"

class Robot : public Move {
public:
    // Robot defeats Ninja, Zombie
    Robot() : Move("Robot", {"Ninja","Zombie"}) {}
};

#endif

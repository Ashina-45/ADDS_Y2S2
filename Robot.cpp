#include "Robot.h"
#include "Zombie.h"
#include "Ninja.h"

std::string Robot::getName() const { return "Robot"; }

bool Robot::beats(const Move* other) const {
    return dynamic_cast<const Zombie*>(other) || dynamic_cast<const Ninja*>(other);
}
#include "Zombie.h"
#include "Monkey.h"
#include "Pirate.h"

std::string Zombie::getName() const { return "Zombie"; }

bool Zombie::beats(const Move* otherMove) const {
  return otherMove->getName() == "Monkey" || otherMove->getName() == "Pirate";
}
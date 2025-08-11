#include "Ninja.h"
#include "Zombie.h"
#include "Pirate.h"

std::string Ninja::getName() const { return "Ninja"; }

bool Ninja::beats(const Move* other) const {
    return dynamic_cast<const Zombie*>(other) || dynamic_cast<const Pirate*>(other);
}
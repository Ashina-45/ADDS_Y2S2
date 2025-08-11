#include "Pirate.h"
#include "Monkey.h"
#include "Robot.h"

std::string Pirate::getName() const { return "Pirate"; }

bool Pirate::beats(const Move* other) const {
    return dynamic_cast<const Monkey*>(other) || dynamic_cast<const Robot*>(other);
}
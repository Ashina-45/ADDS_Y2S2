#include "Monkey.h"
#include "Robot.h"
#include "Ninja.h"

std::string Monkey::getName() const { return "Monkey"; }

bool Monkey::beats(const Move* other) const {
    return dynamic_cast<const Robot*>(other) || dynamic_cast<const Ninja*>(other);
}
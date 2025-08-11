#include "Scissors.h"
#include "Paper.h"

std::string Scissors::getName() const { return "Scissors"; }

bool Scissors::beats(const Move* other) const {
    return dynamic_cast<const Paper*>(other);
}
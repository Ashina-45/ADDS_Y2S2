#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Move.h"

class Zombie : public Move {
 public:
  std::string getName() const override;
  bool beats(const Move* otherMove) const override;
};

#endif
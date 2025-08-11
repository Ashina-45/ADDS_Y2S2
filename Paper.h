#ifndef PAPER_H
#define PAPER_H

#include "Move.h"

class Paper : public Move {
 public:
  std::string getName() const override;
  bool beats(const Move* other) const override;
};

#endif
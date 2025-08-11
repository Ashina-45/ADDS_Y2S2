#ifndef MOVE_H
#define MOVE_H
#include <string>

class Move {
 public:
  virtual std::string getName() const = 0;
  virtual bool beats(const Move* otherMove) const = 0;
  virtual ~Move() = default;
};

#endif
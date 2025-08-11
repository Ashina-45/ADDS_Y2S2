#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "Player.h"

class Human : public Player {
 private:
  std::string name;

 public:
  explicit Human(const std::string& name = "Human");
  std::unique_ptr<Move> makeMove() override;
  std::string getName() const override;
};

#endif
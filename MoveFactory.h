#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H

#include "Move.h"
#include <string>
#include <memory>

std::unique_ptr<Move> createMoveFromName(const std::string& moveName);

#endif

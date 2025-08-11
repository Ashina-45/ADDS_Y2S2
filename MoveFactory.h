#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H

#include "Move.h"
#include <string>
Move* createMoveFromName(const std::string& moveName);

#endif

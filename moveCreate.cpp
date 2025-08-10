#include "moveCreate.h"

// Concrete moves
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Robot.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>

namespace {
    using Maker = std::function<Move*()>;

    std::string norm(std::string s) {
        // lowercase + trim
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return static_cast<char>(std::tolower(c)); });
        auto notspace = [](unsigned char c){ return !std::isspace(c); };
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), notspace));
        s.erase(std::find_if(s.rbegin(), s.rend(), notspace).base(), s.end());
        return s;
    }

    const std::unordered_map<std::string, Maker>& registry() {
        static const std::unordered_map<std::string, Maker> reg = {
            {"rock",     []{ return new Rock();     }},
            {"paper",    []{ return new Paper();    }},
            {"scissors", []{ return new Scissors(); }},
            {"robot",    []{ return new Robot();    }},
            {"monkey",   []{ return new Monkey();   }},
            {"pirate",   []{ return new Pirate();   }},
            {"ninja",    []{ return new Ninja();    }},
            {"zombie",   []{ return new Zombie();   }},
        };
        return reg;
    }
}

Move* createMoveFromName(const std::string& moveName) {
    const auto key = norm(moveName);
    const auto& reg = registry();
    auto it = reg.find(key);
    return (it == reg.end()) ? nullptr : it->second();
}

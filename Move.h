#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <unordered_set>

class Move {
public:
    virtual ~Move() = default;

    // Required by spec
    virtual std::string getName() const { return name_; }

    // Keep pointer overload for compatibility with existing Referee
    virtual bool beats(const Move* other) const {
        return other && beats(*other);
    }

    // Value overload enables cleaner internal logic
    bool beats(const Move& other) const {
        return wins_.find(other.getName()) != wins_.end();
    }

protected:
    // ADT: internal representation hidden behind the interface
    explicit Move(std::string name, std::unordered_set<std::string> wins)
        : name_(std::move(name)), wins_(std::move(wins)) {}

private:
    std::string name_;
    std::unordered_set<std::string> wins_;
};

#endif // MOVE_H
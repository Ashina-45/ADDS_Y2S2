#include "Referee.h"
#include <memory>

Referee::Referee() = default;

Player* Referee::refGame(Player* p1, Player* p2) {
    // Own moves with RAII; players remain outside owners.
    std::unique_ptr<Move> m1(p1->makeMove());
    std::unique_ptr<Move> m2(p2->makeMove());

    if (!m1 || !m2) return nullptr; // undefined per spec; treat as tie

    // Tie if same name OR neither beats the other (covers cross-set no-rules case gracefully)
    const bool same = (m1->getName() == m2->getName());
    const bool p1Win = m1->beats(m2.get());
    const bool p2Win = m2->beats(m1.get());

    if (same || (!p1Win && !p2Win)) return nullptr;
    return p1Win ? p1 : p2;
}

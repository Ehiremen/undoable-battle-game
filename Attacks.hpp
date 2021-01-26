//
//  Attacks.hpp
//  quick-project-space
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "BattleMove.hpp"
#include "Utils.hpp"

using namespace std;

// utility classes that help define various attacks available to actors and generate random damage for each attack accordingly.

class CurseAttack: public BattleMove {
public:
    CurseAttack(Actor* attacker, Actor* target): BattleMove(attacker, target) {
        damageDone = randInt(5, 15);
    }
};

class MeleeAttack: public BattleMove {
public:
    MeleeAttack(Actor* attacker, Actor* target): BattleMove(attacker, target) {
        damageDone = randInt(5, 15);
    }
};

class SpellAttack: public BattleMove {
public:
    SpellAttack(Actor* attacker, Actor* target): BattleMove(attacker, target) {
        damageDone = randInt(0, 20);
    }
};

class SwordAttack: public BattleMove {
public:
    SwordAttack(Actor* attacker, Actor* target): BattleMove(attacker, target) {
        damageDone = randInt(0, 20);
    }
};

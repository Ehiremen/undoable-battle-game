//
//  BattleMoveFactory.hpp
//  quick-project-space
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "BattleMove.hpp"
#include "Attacks.hpp"
using namespace std;

class BattleMoveFactory
{
public:
    static BattleMove* BuildMove(MoveType moveType, Actor* attacker, Actor* target) {
        BattleMove* battleMove = nullptr;
        switch (moveType) {
            case MoveType::Curse:
                battleMove = new CurseAttack(attacker, target);
                break;
            case MoveType::Sword:
                battleMove = new SwordAttack(attacker, target);
                break;
            case MoveType::Spell:
                battleMove = new SpellAttack(attacker, target);
                break;
            case MoveType::Melee:
                battleMove = new MeleeAttack(attacker, target);
                break;
        }
        return battleMove;
    }
};

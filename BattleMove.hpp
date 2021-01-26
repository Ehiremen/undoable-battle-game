//
//  BattleMove.hpp
//  battle-game
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "UndoableCommand.hpp"
#include "Actor.hpp"
#include "GhostActor.hpp"
#include "KnightActor.hpp"

using namespace std;

// class handles battleMoves in order to have them easily undoable
class BattleMove : public UndoableCommand {
public:
    BattleMove(Actor* self, Actor* other)
    :self{ self },
    other{ other }
    {}
    
    void Execute() {
        other->Hit(damageDone);
    }
    
    void Undo() {
        other->Heal(damageDone);
    }
    
protected:
    Actor* self;
    Actor* other;
    int damageDone = 0;
};

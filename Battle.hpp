//
//  Battle.hpp
//  battle-game
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "Actor.hpp"
#include "GhostActor.hpp"
#include "KnightActor.hpp"
#include "ActorFactory.hpp"
#include "CommandManager.hpp"
#include "BattleMove.hpp"
#include "BattleMoveFactory.hpp"
#include "Utils.hpp"

class Battle
{
private:
    CommandManager undoManager;
    Actor* player1;
    Actor* player2;
    bool p1Turn = true, didUndo = false;
    
public:
    Battle(ActorType actor1, ActorType actor2);
    void Start();
    void PlayerTurn();
    void NpcTurn();
};

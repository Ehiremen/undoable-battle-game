//
//  ActorFactory.hpp
//  battle-game
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "Actor.hpp"
#include "GhostActor.hpp"
#include "KnightActor.hpp"

using namespace std;

enum ActorType {
    Ghost,
    Knight
};

// factory class to handle creating the different actors in the game
class ActorFactory {
public:
    static Actor* CreateActor(ActorType actorType) {
        Actor* actor = nullptr;
        switch (actorType) {
            case ActorType::Ghost:
                actor = new GhostActor();
                break;
            case ActorType::Knight:
                actor = new KnightActor();
                break;
        }
        return actor;
    }
};

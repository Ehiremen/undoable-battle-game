//
//  GhostActor.hpp
//  quick-project-space
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "Actor.hpp"

using namespace std;

// initialize move list for Ghosts
class GhostActor: public Actor {
public:
    GhostActor(): Actor(100, "Ghost") {
        moves.push_back(Spell);
        moves.push_back(Curse);
    }
};

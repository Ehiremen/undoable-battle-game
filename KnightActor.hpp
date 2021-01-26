//
//  KnightActor.hpp
//  quick-project-space
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "Actor.hpp"

using namespace std;

// initialize move list for Knights
class KnightActor: public Actor {
public:
    KnightActor(): Actor(100, "Knight") {
        moves.push_back(Sword);
        moves.push_back(Melee);
    }
};

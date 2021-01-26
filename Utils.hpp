//
//  Utils.hpp
//  quick-project-space
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include <map>
using namespace std;

// various utility functions for various parts of the project

// make all members static to avoid duplication when #include is used in multiple places
static int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

static map<ActorType, string> actorDisplayName{
    {ActorType::Ghost, "Ghost"},
    {ActorType::Knight, "Knight"},
};

static map<MoveType, string> moveDisplayName{
    {MoveType::Curse, "Curse"},
    {MoveType::Melee, "Melee"},
    {MoveType::Spell, "Spell"},
    {MoveType::Sword, "Sword"}
};


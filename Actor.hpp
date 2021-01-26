//
//  Actor.hpp
//  battle-game
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum MoveType {
    Spell,
    Curse,
    Sword,
    Melee
  };

//Base class for Actors in the game
class Actor {
private:
    string type;
protected:
    int health;
    vector<MoveType> moves;
    
public:
    Actor (int health, string type) : health(health), type(type) {}
    
    virtual void Hit(int damage) {
        health -= damage;
        health = max(0, health);
        cout << "Hit for " << damage << " damage" << endl;
    }
    
    virtual void Heal(int amount) {
        health += amount;
        cout << "Got " << amount << " health back" << endl;
    }
    
    const vector<MoveType>& GetMoves() const {
        return moves;
    }
    
    bool IsDead() const { return health <= 0; }
    
    friend ostream& operator<<(ostream& out, const Actor& actor) {
        out << "(" << actor.type << ")" << " has " << actor.health << " hp";
        if (actor.IsDead()) {
            out << " (deceased)";
        }
        return out;
    }
};

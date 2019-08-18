//Has Actor and BattleMove class definitions

#pragma  once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum MoveType {AttackOne, AttackTwo, HealMove};
enum ActorType {Ghost = 1, Knight, Warrior};

class Actor{
protected:
    string type;
    int health;
    int damage;
    int actualHeal;
    int actualDamage;
    vector<MoveType> moves;
    bool dead;
public:
    Actor(int health, string type)
            :health{health}, type{type}
    {}
    virtual void Attack(Actor& actor) = 0;
    virtual void Hit(int damageDealt){  //public method to hit THIS actor with damage
        actualDamage = damageDealt;
        health -= damageDealt;
        health = max(0, health);
        if(health == 0)
            dead = true;
    }

    virtual void Heal(int amount) {    //public method to heal this actor with an amount
        actualHeal = amount;
        health += amount;
    }
    virtual void GetMoves() {    //vector of MoveTypes
        for (auto m: moves){
            cout << m;
        }
    }
    vector<MoveType> CheckMoves(){
        return this->moves;
    }
    int GetDamageTaken(){
        return actualDamage;
    }
    int GetHealTaken(){
        return actualHeal;
    }
    bool IsDead(){ return this->dead;}
    string GetInfo(){ return type + ", (" + to_string(health) + ")";}

    friend ostream& operator<<(ostream& out, const Actor& a);
};
ostream& operator<<(ostream& out, const Actor& a){
    out << a.type << ", (" << a.health << ")";
    if(a.dead)
        out << " (deceased)";
    return out;
}

class Ghost: public Actor {
public:
    Ghost(int health) : Actor(health, "Ghost") {
        type = "Ghost";
        dead = false;
        moves.emplace_back(AttackOne);
        moves.emplace_back(HealMove);
    }

    void Attack(Actor &actor) override {
        actor.Hit(damage);
    }
};


class Knight: public Actor{
public:
    Knight(int health):Actor(health, "Knight"){
        type = "Knight";
        dead = false;
        moves.emplace_back(AttackTwo);
        moves.emplace_back(HealMove);
    }
    void Attack(Actor& actor) override {
        actor.Hit(damage);
    }
};

class Warrior: public Actor{
public:
    Warrior(int health):Actor(health, "Warrior"){
        type = "Warrior";
        dead = false;
        moves.emplace_back(AttackOne);
        moves.emplace_back(AttackTwo);
    }
    void Attack(Actor& actor) override {
        actor.Hit(damage);
    }
};

class BattleMove{
private:
    Actor* self;
    Actor* other;
    MoveType moveDone;
public:
    BattleMove(Actor* self, Actor* other)
            :self{self}, other{other}
    {}

    virtual void Execute() = 0;
    // void virtual Undo() = 0;
    string GetSelfInfo(){ return self->GetInfo();}
    string GetOtherInfo() { return  other->GetInfo();}
    MoveType GetMoveDone(){ return  moveDone;}
};

class DoAttackOne: public BattleMove{
protected:
    Actor* a_self;
    Actor* a_other;
    MoveType  moveDone = AttackOne;
public:
    DoAttackOne(Actor* attacker, Actor* defender)
            :a_self{attacker}, a_other{defender}, moveDone{moveDone}, BattleMove(attacker, defender)
    {}

    void Execute() override{
        cout << a_self->GetInfo() << " used: AttackOne" << endl;
        int attackValue = (rand()%6) + 10;  // generates number in the range 10..15
        cout << a_other->GetInfo() << " is hit with " << attackValue << " damage" << endl;
        a_other->Hit(attackValue);
    }
};

class DoAttackTwo: public BattleMove{
protected:
    Actor* a_self;
    Actor* a_other;
    MoveType  moveDone = AttackTwo;
public:
    DoAttackTwo(Actor* attacker, Actor* defender)
            :a_self{attacker}, a_other{defender}, moveDone{moveDone}, BattleMove(attacker, defender)
    {}

    void Execute() override{
        cout << a_self->GetInfo() << " used: AttackTwo" << endl;
        int attackValue = rand()%26;  // generates number in the range 0..25
        cout << a_other->GetInfo() << " is hit with " << attackValue << " damage" << endl;
        a_other->Hit(attackValue);
    }
};

class DoHeal: public BattleMove{
protected:
    Actor* a_self;
    Actor* a_other;
    MoveType  moveDone = HealMove;
public:
    DoHeal(Actor* attacker, Actor* defender)
            :a_self{attacker}, a_other{defender}, moveDone{moveDone}, BattleMove(attacker, defender)
    {}

    void Execute() override{
        cout << a_self->GetInfo() << " used: Heal" << endl;
        int healValue = (rand()%6) + 10;           // generates number in the range 10..15
        cout << a_self->GetInfo() << " is healed by " << healValue << " hp" << endl;
        a_self->Heal(healValue);
    }
};
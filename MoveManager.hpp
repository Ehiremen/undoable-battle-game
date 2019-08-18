//Controls execution of player moves; also keeps command history for UNDO actions
#pragma once

#include <iostream>
#include <vector>
#include "Stack.hpp"
#include "GameClasses.hpp"

using namespace std;

Actor* attacker;
Actor* defender;

int tryMove(Actor* a_self, Actor* a_other){
    int pickMove = rand()%2;
    int moveToDo = a_self->CheckMoves()[pickMove];
    int typeOfMove; //attack = 0, defend = 1
    MoveType moveDone;
    BattleMove* doingMove;

    switch (moveToDo){
        case 0: moveDone = AttackOne; doingMove = new DoAttackOne(a_self, a_other); typeOfMove = 0; break;
        case 1: moveDone = AttackTwo; doingMove = new DoAttackTwo(a_self, a_other); typeOfMove = 0; break;
        case 2: moveDone = HealMove; doingMove = new DoHeal(a_self, a_other); typeOfMove = 1; break;
    }
    doingMove->Execute();
    return typeOfMove;
}

enum CommandType{
    PlayerCommand
};

class ICommand{
public:
    virtual void Execute(Actor* attacker, Actor* defender)=0;
    virtual ~ICommand(){
    }
};

class IUndoableCommand: public ICommand{
    int valueForUndo;   //keeps track of damage/heal done
    int moveIsDefend;   //keeps track of whether the move is an attack or heal type. (0 for attack, 1 for defend)
    Actor* p_attacks;   //keeps track of which player made the move at each command
    Actor* p_attacked;
public:
    virtual void Undo(Actor* a1, Actor* a2)=0;
};

class DoMoveCommand: public IUndoableCommand {
int valueForUndo;
int moveIsDefend;
Actor* p_attacks;
Actor* p_attacked;
public:
    void Execute(Actor* a1, Actor* a2) override{
        moveIsDefend = tryMove(a1, a2);
        if (moveIsDefend == 1){
            p_attacks = a1;
            p_attacked = a2;
            valueForUndo = p_attacks->GetHealTaken();
        }
        else if (moveIsDefend == 0){
            p_attacks = a1;
            p_attacked = a2;
            valueForUndo = p_attacked->GetDamageTaken();
        }
    }

    void Undo(Actor* a1, Actor* a2){
        if (moveIsDefend == 1){
            cout << "Undoing heal by " << *p_attacks << endl;
            p_attacks->Hit(valueForUndo);   //hit a healed player to undo their heal
        }
        else if (moveIsDefend == 0){
            cout << "Undoing hit on " << *p_attacked << endl;
            p_attacked->Heal(valueForUndo); //heal an attacked player to undo the attack
        }
    }
};

class CommandManager{
private:
    Stack<IUndoableCommand*> stack;
public:
    CommandManager():
            stack{Stack<IUndoableCommand*>()}
    {}

    void ExecuteCommand(CommandType commandType){
        IUndoableCommand* cmd;
        cmd = new DoMoveCommand();
        cmd->Execute(attacker, defender);
        stack.Push(cmd);
    }

    void UndoLastCommand(){
        if(stack.IsEmpty()){
            cout << "Nothing to undo." << endl;
            return;
        }
        auto cmd = stack.Top();
        cmd->Undo(attacker, defender);
        delete stack.Top();
        stack.Pop();
    }

    ~CommandManager(){
        while(!stack.IsEmpty()){
            delete stack.Top();
            stack.Pop();
        }
    }
};
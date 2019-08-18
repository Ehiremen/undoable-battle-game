//The main game logic
#pragma once

#include <vector>
#include <string>
#include <ctime>
#include "Stack.hpp"
#include "GameClasses.hpp"
#include "MoveManager.hpp"

using namespace std;

int chooseMove();
void setupGame(vector<Actor*>&);
void game(Actor*, Actor*);
string actorTypeToString(int input);


string actorTypeToString(int input){ //to help print the corresponding ActorType for the enums
    string actorString;
    switch (input){
        case Ghost: actorString = "Ghost"; break;
        case Knight: actorString = "Knight"; break;
        case Warrior: actorString = "Warrior"; break;
        default: cout << "Actor not found" << endl;
    }
    return actorString;
}

void setupGame(vector<Actor*> &actors){
    int playerChoice;
    int opponentChoice;
    int startingHealth = 100;

    cout << "Welcome to the Dungeon" << endl;

    while (true) {
        cout << "Select a player:" << endl;
        cout << "1) Ghost" << endl;
        cout << "2) Knight" << endl;
        cout << "3) Warrior" << endl;
        cin >> playerChoice;
        if ((playerChoice > 0) && (playerChoice < 4)) {
            cout << "You selected: " << actorTypeToString(playerChoice) << endl << endl;

            switch (playerChoice){
                case 1: actors.emplace_back(new class Ghost(startingHealth)); break;
                case 2: actors.emplace_back(new class Knight(startingHealth)); break;
                case 3: actors.emplace_back(new class Warrior(startingHealth)); break;
            }
            break;
        }
        else {
            cout << "Invalid selection" << endl << endl;
        }
    }

    while (true) {
        cout << "Select an opponent:" << endl;
        cout << "1) Ghost" << endl;
        cout << "2) Knight" << endl;
        cout << "3) Warrior" << endl;
        cin >> opponentChoice;
        if ((opponentChoice > 0) && (opponentChoice < 4)) {
            cout << "You selected: " << actorTypeToString(opponentChoice) << endl << endl;
            switch (opponentChoice){
                case Ghost: actors.emplace_back(new class Ghost(startingHealth)); break;
                case Knight: actors.emplace_back(new class Knight(startingHealth)); break;
                case Warrior: actors.emplace_back(new class Warrior(startingHealth)); break;
            }
            break;
        }
        else {
            cout << "Invalid selection" << endl << endl;
        }
    }

    cout << "Beginning match!" << endl;
    for (auto a: actors){
        cout << *a << endl;
    }
    cout << "-----------------------------------" << endl;
}

int chooseMove(){
    int moveChosen;
    while(true) {
        cout << "Choose move:" << endl;
        cout << "1) P1 -> P2" << endl << "2) P2 -> P1" << endl << "3) Undo" << endl;
        cin >> moveChosen;

        if ((moveChosen >= 1) && (moveChosen <=3)) break;
        else cout << "Selected move not found :(" << endl;
    }
    return moveChosen;
}

void game(Actor *player1, Actor *player2){
    CommandManager mgr;

    while(!(player1->IsDead()) && !(player2->IsDead())){
        int currentMove = chooseMove();
        switch (currentMove){
            case 1: attacker = player1, defender = player2 /*fighter = 1*/; mgr.ExecuteCommand(PlayerCommand); break;
            case 2: attacker = player2, defender = player1 /*fighter = 2*/; mgr.ExecuteCommand(PlayerCommand); break;
            case 3: mgr.UndoLastCommand(); break;
        }
        cout << "[PLAYER: " << *player1 << "]" <<  "[OPPONENT: " << *player2 << "]" << endl;
    }
    cout << endl << "Winner is: ";
    player1->IsDead()? cout<< "[OPPONENT: " << player2->GetInfo() :cout <<"[PLAYER: " << player1->GetInfo();
    cout << "]" << endl;

}
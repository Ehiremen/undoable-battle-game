//
//  Game.hpp
//  battle-game
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "Battle.hpp"

using namespace std;

class Game {
private:
    
public:
    Game () {
        cout << "---------------------\n    Starting Game\n---------------------\n";
    }
    ~Game () {
        cout << "---------------------\n    Game Over\n---------------------\n";
    }
    
    bool playOrQuit() {
        int choice;
        cout << "\nWould you like to:" << endl;
        cout << "(1) Start a battle" << endl;
        cout << "(2) Quit the game" << endl;
        
        do{
            cout << "I pick: ";
            cin >> choice;
            
            if (choice < 1 || choice > 2) {
                cout << "\tInvalid choice, RETRY" << endl;
            }
        } while(choice!=1 && choice!=2);
        
        return (choice==1 ? true : false);
    }
    
    void endGame() {
        cout << endl << "Thanks for playing!" << endl << endl;
    }
    
    ActorType chooseFighter() {
        int choice;
        cout << "(1) Ghost" << endl;
        cout << "(2) Knight" << endl;
        
        do{
            cout << "I pick: ";
            cin >> choice;
            
            if (choice < 1 || choice > 2) {
                cout << "\tInvalid choice, RETRY" << endl;
            }
        } while(choice!=1 && choice!=2);
        
        return (choice==1 ? Ghost : Knight);
    }
    
    void play() {
        bool isPlaying;
        ActorType p1, p2;
        
        for (;;) {
            isPlaying = playOrQuit();
            if (!isPlaying) {
                endGame();
                break;
            }
            
            cout << "\n------------------\n    NEW ROUND\n------------------\n";
            cout << "\nChoose your fighter:" << endl;
            p1 = chooseFighter();
            
            cout << "\nChoose your opponent:" << endl;
            p2 = chooseFighter();
            
            Battle(p1, p2);
            
            cout << "\n------------------\n    ROUND OVER\n------------------\n";
        }
    }
};

//
//  Battle.cpp
//  battle-game
//
//  Created by Ehiremen Ekore on 1/26/21.
//

#include "Battle.hpp"

Battle:: Battle(ActorType actor1, ActorType actor2) {
    player1 = ActorFactory::CreateActor(actor1);
    player2 = ActorFactory::CreateActor(actor2);
    
    cout << endl << actorDisplayName[actor1] << " vs " << actorDisplayName[actor2] << " FIGHT!" << endl;
    Start();
}

void Battle:: Start() {
    do {
        didUndo = false;
        if (p1Turn) {
            PlayerTurn();
            p1Turn = false;
        }
        else {
            NpcTurn();
            p1Turn = true;
        }
        
        cout << "\n++++++++++++++++++++++++++\n";
        cout << "(ME) " << *player1 << endl << "(OPP) " << *player2;
        cout << "\n++++++++++++++++++++++++++\n\n";
        
    } while (!player1->IsDead() && !player2->IsDead());
    
    cout << "Battle is over!\n\t" << (player1->IsDead() ? "PLAYER 2 " : "PLAYER 1 ") << (player1->IsDead() ? *player2 : *player1) << " and is the winner\n\n";
}

void Battle:: PlayerTurn() {
    vector<MoveType> moves = player1->GetMoves();
    MoveType mt;
    bool wantToAttack;
    int choice;
    
    cout << "I want to:" << endl;
    cout << "(1) Attack" << endl;
    cout << "(2) Heal" << endl;
    
    do{
        cout << "I pick: ";
        cin >> choice;
        
        if (choice < 1 || choice > 2) {
            cout << "\tInvalid choice, RETRY" << endl;
        }
    } while(choice!=1 && choice!=2);
    
    wantToAttack = choice==1 ? true:false;
    
    if (!wantToAttack) {
        cout << "\nPlayer 1 has ";
        didUndo = undoManager.Undo();
        if (!didUndo) PlayerTurn();
    }
    else {
        cout << "\nChoose attack to perform: \n";
        for (int i=0; i<moves.size(); i++) {
            cout << "("  << (i+1) << ") " << moveDisplayName[moves[i]] << endl;
        }
        
        for (;;){
            cout << "I pick: ";
            cin >> choice;
            
            mt = moves[choice-1]; // because arrays start at index 0.
            auto it = find(moves.begin(), moves.end(), mt);
            if (it == moves.end()) {
                cout << "\tInvalid choice, RETRY" << endl;
            }
            else {
                break;
            }
        }
        
        BattleMove* bm = BattleMoveFactory::BuildMove(mt, player1, player2);
        cout << "\nPlayer 1 " << moveDisplayName[mt] << " has ";
        undoManager.Execute(bm);
    }
}

void Battle:: NpcTurn()  {
    vector<MoveType> moves = player2->GetMoves();
    MoveType mt = moves[randInt(0, moves.size()-1)];
    
    BattleMove* bm = BattleMoveFactory::BuildMove(mt, player2, player1);
    cout << "Player 2  " << moveDisplayName[mt] << " has ";
    undoManager.Execute(bm);
}

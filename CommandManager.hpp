//
//  CommandManager.hpp
//  battle-game
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include "Stack.hpp"
#include "UndoableCommand.hpp"

using namespace std;

class CommandManager
{
private:
    Stack<UndoableCommand*> stack;
    
public:
    CommandManager() :stack{ Stack<UndoableCommand*>(100) } {}
    void Execute(UndoableCommand* command) {
        command->Execute();
        stack.Push(command);
    }
    bool Undo() { // return a bool to let us know whether an undo happened or not
        if(stack.IsEmpty()){
            cout << "Nothing to undo.\n\n";
            return false;
        }
        stack.Top()->Undo();
        stack.Pop();
        return true;
    }
};

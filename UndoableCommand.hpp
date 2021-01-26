//
//  UndoableCommand.hpp
//  battle-game
//
//  Created by Ehiremen Ekore on 11/22/20.
//

#pragma once
#include <cstdlib>

using namespace std;

class UndoableCommand
 {
   public:
     virtual void Execute()=0;
     virtual void Undo()=0;
 };

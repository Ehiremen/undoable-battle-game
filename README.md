# undoable-battle-game
A simple turn taking game that implements classes and undoable commands in c++.

The game is set up with Player 1 being whoever is controlling the console and Player 2 being an npc. Player 1 picks what kind of character (Actor) they'd like to be and also pick what kind of opponent they'd go against.

## Gameplay
1. During the game, Player 1 is able to:
   * Attack: Choose aany of the moves available to their Actor and use that attack on their opponent
   * Heal: Undo the last attack performed by their opponent. This is implemented using Stacks.

2. Player 2 is only able to perfrom attacks. This is done by choosing a random attack from their available moves.

# README                                    

## ABOUT                               
* NAME       : AMGBattleship
* Author     : Abel Gancsos
* Version    : v. 1.0.0

## Implementation Details  
This command-line utility serves as a text-based console version of the classic Battleship board game.  Typically there would be two users that would have the same number of ships on the board at different locations and they both take turns trying to sink the other users ships.  In the real game, each ship would have a different length and thus a different number of required shots to sink it; however, in this version of the game, every ship is represented by the same size, but in different locations.  After each shot, the current player will only see there board, locations of their ships, what shots were taken against their ships, and which ships were hit/sunk.  The board is then cleared in preparation for the next player.

### Markings
* -: Position is filled with water.  No shot.
* *: Position is filled with water.  Shot.
* X: Position is filled with a ship.  Hit.

### Assumptions:
* Users play the game on the same command line, but their own context during their turn.
* The game may add other attacks in the future.
* There will only be 2 players at a time on the board.
* A ship will only take up one block on the board.  This may change in future releases.
* The ship count can not and should not be larger than the map size.
* Both players will start with the same number of ships.
* The board width and height are the same for each player.
* The values for the board height and board width are for each side/player (not the total board).
* The current player will only see their own board.

## Implementation Description

## FLAGS                                    
The folling flags can be used to configure the game board
* -height : Height of the board (default: 5)
* -width  : Width of the board (default: 5)
* -count  : Number of ships on the board (default: 3)

## PREREQUISITES
### G++ compiler
#### Windows
Should come with Visual Studio 2017 in the form of devenv, but you can also try using Bloodshed Dev C++
#### Mac
Should come with XCode command-line tools
#### Linux
Should be installable using internal package installer
### CMake
#### Windows
Should come with Visual Studio 2017 
#### Mac
Can be installed from https://cmake.org/download/
#### Linux
Can be installed from https://cmake.org/download/

## Build
This can be built either using one of the run scripts or manually using the following instructions

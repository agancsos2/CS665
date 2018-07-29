# README                                    

## ABOUT                               
* NAME       : AMGBattleship
* Author     : Abel Gancsos
* Version    : v. 2.0.0

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

## Refactoring 
As was mentioned for the first release of AMGBattleship, certain items were intentionally left in the initial release that may have been considered messy or not best practice.  For example, one item that was declared to be an issue in the initial release was that the implementation not only really used one client (command-line session) to manage the game board, which required that both players be located in the same physical location, but the whole game was encapsulated in the main system.  This combination then required multiple attributes in the client to handle both players, which made the transferring of the data between components unsafe and messy.  Ideally, the main system would be in a completely separate location and the board would become the true client, which would be split up into multiple instances.  Then using an AMGBattleshipData class to hold the games data, each client would build it’s own requests and therefore allow for more security as well as flexibility.  These items were intentionally left in the first release because the product owner decided that shipping a functional product in a timely manner was more important than having perfect code.  This release focused primarily on code cleanup as well as stabilizing the product.  

This release focuses on addressing the issue where one board was used to manage both players data.  In order to do this, the data also had to be made separate so that it could be easily transferred between components, thus the AMGBattleshipData class was added to the product.  At this time, each board, which by current design is considered to be the true client, contains it’s own data object to maintain the players information.  As the current release still uses one main system to manage both players, this then puts the system in a better position to implement a client-server game play because the data is separate from the main system and is apart of the client.  

A third item that was focused on during the refactoring process was general code cleanup and stabilization.  The way that this was approach was that any duplicated methods were removed and any undocumented code was corrected with documentation.  Certain methods do seem to be duplicated; however, the information that is involved is under a different context.  For example, the AMGBattleshipBoard. SetShipCount() method exists to set the number of games on the player’s board, which the AMGBattleshipData. SetShipCount() method is used to calculate the attacks as well as if the game play has completed.  Another benefit of certain duplicated methods is to ensure that the data is safely  set without a risk of injection.  

With any refactoring, there is a risk for the system to change in behavior, especially if the changes are significant.  As the data had to be split apart to allow multiple client instances was not a small change, despite it being implemented in a timely manner, the behavior of the system could have changed.  During testing, no severe change to behavior has occurred, one change that was observed is that while generating the ships for the players, there is a one or two second delay.  Otherwise, the data is displayed as it did in the initial release, which by design would display the player’s ships, correct markings if they were hit or not, and then the opponents shots.  It was by design that the current player is unable to see the opponent’s board because by design of the original Battleship game only offers the location of where the player shot and if it was a hit or miss.  It does not offer a visual representation of the opponent’s board and thus AMGBattleship by design will only list where the player shot on the opponent’s board.  

## Implementation Description


## FLAGS                                    
The following flags can be used to configure the game board
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

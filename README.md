# my_sokoban
The goal of this project is to create the game sokoban.
# Game
## Rules
You have to put all the boxes in storage locations.  
  
If you stuck all the boxes, you loose and the program exit 1.  
If you put all the boxes in storage locations, you win and the program exit 0.
## Legend
- 'P' represent the player.
- 'X' represent the boxes.
- 'O' represent the storage locations.
- '#' represent the walls.
# How to execute
To run the program, type `make` and then execute the file `./my_sokoban` with a map defined in `maps`.  
To run the tests, type `make tests run`.  
  
The folder `bonus` is the exact same project, but the difference is that the display of the game is different. There is color for walls, boxes, storage locations and player. To have the project with colors, go on `bonus` and do the same thing as in the root.
# How to play
- left, right, top and bottom arrows to move the player.
- echap to quit the game.
- use space to reset the game.

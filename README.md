# Watan CS246 Final Project
Contributors: Daniel Costiuc, Johan Sebastiampillai, Sean Grecco

# Introduction
C++ implementation of a video game called Watan, which is variant of the game Settlers of Catan, with the board based on the Univeristy of Waterloo.

# Compilation
Makefile bash script is included. Use the command make in unix environment. It will compiled with the program name Watan and be excecuted by ./watan

# Commands for Beginning of Turn
• load: sets the dice of the current student to be loaded dice
• fair: sets the dice of the current student to be fair dice
• roll: rolls the current student’s dice

# Commands for End of Turn
• board: prints the current board
• status: prints the current status of all students in order from student 0 to 3
• criteria: prints the criteria the current student has currently completed
• achieve <goal\#>: attempts to achieve the goal at <goal\#>
• complete <criterion\#>: attempts to complete the criterion at <criterion\#>
• improve <criterion\#>: attempts to improve the criterion at <criterion\#>
• trade <colour> <give> <take>: attempts to trade with student <colour> giving one resource of type <give> and receiving one resource of type <take>
• next: passes control onto the next student in the game.
• save <file>: saves the current game state to <file>
• help: prints out the list of commands

# Command-line interface
• -seed xxx sets the random number generator’s seed to xxx.
• -load xxx loads the game saved in file xxx.
• -board xxx loads the game with the board specified in the file xxx instead of using random generation.

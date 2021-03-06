  ----  ----- |   | |----- |      |       ----
 |    |   |   |   | |      |      |      |    |
 |    |   |   |---| |--    |      |      |    |
 |    |   |   |   | |      |      |      |    |
  ----    |   |   | |----- |----- |-----  ----

Welcome to the game of Othello!

Written by
        Bryce Lewis (bklewis@brynmawr.edu),
        Jia Li (jli01@brynmawr.edu), and
        Emily Williams (ewilliam03@brynmawr.edu)
in April 2014 for Professor Jia Tao's Programming Paradigms class at Bryn Mawr College.

The Game:
        Othello is a two-person game played with 64 tokens on an eight-by-eight grid.
        Every individual token has two sides, X and O, each of which represents a player.  
	The goal of the game is to have more tokens of your symbol than your opponent's 
	symbol on the grid by the end of the game.

Gameplay:
        To begin, the central four squares of the board will be filled with four tokens:
        X on the the upper left and bottom right corners, and O on the upper right and
        bottom left corners.

        Possible moves that a player may make will be marked on the board by an 'M' at
        the start of their turn.  To make a move, a player must place a token of their
        symbol on an M, placed ajacent to a token of the opponent's symbol (horizontally,
        vertically, or  diagonally) in such a way that one or more of the opponent's
        tokens are sandwiched between the new token and a "base" token (any of the current
        player's tokens already on the board).  There can be no empty spaces in the
        squares between the new and base tokens.  All of the tokens between the new
        and base tokens are then flipped to the current player's symbol, and the turn
        is over.  If a player cannot place a token in a way that meets these conditions,
        their turn is passed and the next player may move.  If neither player can make
        a move, no matter how many tokens are on the board, the game is over.  The winner
        is the one with the most tokens of their symbol on the board when the game ends.

Starting a Game:
        When you start a game you will be prompted to choose one of three options:
                (1) Human vs. Computer,
                (2) Human vs. Human, or
                (3) Computer vs. Computer.
        Choose mode (1) to play against the computer's AI or mode (2) to play against a
        friend.  Choose mode (3) to watch the computer play itself! Once you have chosen
        your game mode there is an additional option for "bonus mode."  In bonus mode
        there is one square on the board which will give you a bonus if you play on it.
        Whoever plays on this square will not only get the token they placed and any
        of their opponent's that they flipped, but one additional token belonging to
        their opponent will be randomly selected and flipped to the current player's
        token.  Once the modes have been chosen, the first player will be randomly
        selected and the game will begin.

To Start the Progam:
        In the directory you have saved the Othello source files, enter the following commands:
                $ make 
				$ make clean
                $ ./Othello
        This will bring you to the prompt to choose your mode and play the game!

Enjoy the game!



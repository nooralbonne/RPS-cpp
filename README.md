# Rock-Paper-Scissors Game
A simple console-based Rock-Paper-Scissors game implemented in C++.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [How to Play](#how-to-play)
- [Example Gameplay](#example-gameplay)
- [License](#license)

## Introduction
This is a classic Rock-Paper-Scissors game where a player competes against the computer. The player can choose to play one or more rounds, and the game will keep track of the score. At the end of all rounds, the game will declare the winner.

## Features
- Play multiple rounds of Rock-Paper-Scissors.
- Randomized computer choices.
- Tracks the number of wins, losses, and draws.
- Option to replay the game as many times as desired.

## How to Play
The game will first ask you how many rounds you want to play (between 1 and 10).
In each round, you will be prompted to choose either:
[1] Stone
[2] Paper
[3] Scissors
The computer will make a random choice, and the game will determine the winner of that round.
After all rounds are completed, the final winner (player, computer, or draw) will be displayed.
You will be asked if you want to play again. Enter Y to play another game or N to quit.

## Example Gameplay
How many rounds 1 to 10 play? 3
Round [1] begins:
Your choice: [1] Stone, [2] Paper, [3] Scissors? 1
-----------------[1]----------------
Player choice   : [1] Stone
Computer choice : [2] Paper
Round winner    : Computer
--------------------------------------------------------------

Round [2] begins:
Your choice: [1] Stone, [2] Paper, [3] Scissors? 2
-----------------[2]----------------
Player choice   : [2] Paper
Computer choice : [3] Scissors
Round winner    : Computer
--------------------------------------------------------------

Round [3] begins:
Your choice: [1] Stone, [2] Paper, [3] Scissors? 3
-----------------[3]----------------
Player choice   : [3] Scissors
Computer choice : [1] Stone
Round winner    : Computer
--------------------------------------------------------------

--------------[Game Results]---------------
Game Rounds        : 3
Player1 won times  : 0
Computer won times : 3
Draw times         : 0
Final Winner       : Computer
--------------------------------------------------------------

                 * Computer Wins! *

Do you want to play again? Y/N

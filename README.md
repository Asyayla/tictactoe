# Tic Tac Toe – AI Game

This repository contains a Tic Tac Toe game implemented in C++ where the player can compete against a simple AI.

---

## Features

- Play Tic Tac Toe against an AI
- User selects their move (1-9 positions)
- AI blocks and tries to win
- Detects win, lose, and tie
- Clean input validation

---

## Technical Details

- Written in C++
- Single-file implementation (`newtictactoe.cpp`)
- Functions for game logic: 
  - `checkWinner`, `checkTie`, `playerMove`, `aiMove`, `displayBoard`, `cleanBoard`
- Handles invalid inputs gracefully
- Simple AI with basic strategy (win/block/center/corners)

---

## How to Run

```bash
g++ newtictactoe.cpp -o tictactoe
./tictactoe

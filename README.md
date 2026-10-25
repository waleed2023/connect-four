# Connect Four

A simple Connect Four game written in C project for my studies at the University of Freiburg.

The game runs in the terminal and supports two players or playing against the computer. I also implemented a way to save and load games.

## Getting started

Run the game:

```bash
./4          # Two players
./4 --ai     # Play against the computer
./4 --load   # Load a saved game
```

## How it works

The game uses a 7x6 board. Players take turns choosing a column, and the first to connect four pieces wins.

The computer opponent uses a few basic rules to decide where to place its next piece, including blocking the opponent's moves.

Games can be saved and continued later.

## Build and tests

```bash
make test
make debug
make clean
```

## Notes

This was one of my earlier C projects, originally written in 2019. I kept the implementation mostly as it was at the time.

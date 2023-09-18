# So Long

This repository contains the implementation of the So_long project, which is part of the curriculum at 42 School. The So_long project focuses on creating a simple 2D game using the Minilibx, a graphics library provided by 42 School.

## Project Description

So_Long is a 2D game where the player controls a character (e.g., a player icon) that must navigate a maze-like environment to reach a goal while avoiding obstacles. The project involves reading maps from a file, rendering the game on the screen, and handling player movements.

## Features

- Reading a map from a file to create the game environment.
- Displaying the game using Minilibx.
- Handling player movements (e.g., walking, collecting items, reaching the goal).
- Displaying the number of steps taken by the player.

## Usage

1. Clone the repository or download the relevant files.
2. Compile the code using the provided Makefile.
3. Run the executable, providing the path to a valid map file.

Example usage:
```bash
./so_long maps/map.ber
```

## Code Structure

The code is structured to handle the following main tasks:

1. Reading the map from a file.
2. Initializing the game environment and assets.
3. Rendering the game on the screen.
4. Handling player movements and interactions.

The main program is contained in the `so_long.c` file, and relevant functions are organized in separate C files.

## Map Format

The map is read from a `.ber` file, where each character represents a different element:
- `1`: Wall
- `0`: Floor
- `C`: Collectible item
- `E`: Exit/goal
- `P`: Player start position
- `X`: Enemy (bonus)

## Documentation

For more detailed information about the project, including its requirements and specifics, please refer to the official project documentation and subject provided by 42 School.

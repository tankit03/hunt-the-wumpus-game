# Hunt the Wumpus Game

## Introduction

Hunt the Wumpus is a text-based adventure game set inside the cave of the Wumpus, a fearsome monster who guards its gold treasure. Your goal is to guide an adventurer, kill the Wumpus, find the hidden gold, and escape alive. Be cautious, as the cave is filled with hazards, and the Wumpus is not an easy foe to defeat.

## Game Elements

### The Adventurer

You control the adventurer, and each turn you can take one of two actions:

- **Move:** Navigate through tunnels to an adjacent room.
- **Fire an Arrow:** You start with three arrows. You can fire one in any direction (north, south, east, or west). Arrows continue until they hit a wall or travel through three rooms. If an arrow hits the Wumpus, you win!

### The Wumpus

The Wumpus is usually asleep, but it can wake up if you enter its room or shoot and miss. If it awakens and finds you in the same room, you'll become its meal, ending the game. If it wakes up from an arrow, it may move to another random empty room to avoid detection.

### Hazards

The cave contains two types of hazards:

- **Bottomless Pits:** Two rooms have bottomless pits. Falling into one is fatal.
- **Super Bats:** Two rooms have super bats. Entering such a room will cause a bat to grab you and transport you to another random room, which could be dangerous.

### The Gold

The gold is hidden in a room without hazards or the Wumpus. If you enter such a room, you automatically pick up the gold.

### Percepts

When you are in a room adjacent to an event, you'll receive percepts to help you identify nearby dangers or treasures:

- **Wumpus:** "You smell a terrible stench."
- **Super Bats:** "You hear wings flapping."
- **Bottomless Pit:** "You feel a breeze."
- **Gold:** "You see a glimmer nearby."

Remember that percepts don't pinpoint the exact location of the event, only that it's close.

## Program Requirements

### User Interface

- Your program allows the user to play Hunt the Wumpus as described.
- The cave's size (number of rooms on one side) is specified as input.
- The program displays the grid, indicating the player's position with a symbol (e.g., *).
- Debug mode can be activated with "true," showing all locations (Wumpus, bats, pits, gold, player, escape rope).

### Gameplay

- Use "w" (north), "a" (west), "s" (south), or "d" (east) to navigate.
- Use space followed by "w", "a", "s", or "d" to fire an arrow in that direction.



Have fun playing Hunt the Wumpus!

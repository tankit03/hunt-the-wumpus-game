# Hunt the Wumpus Game Program Description

## Introduction

This program is a text-based adventure game called "Hunt the Wumpus." In this game, players are tasked with exploring a dark cave filled with dangers and treasures. The main objective is to hunt down the Wumpus, a menacing monster guarding a hidden gold treasure, and escape the cave alive. The game unfolds in the following manner:

1. The Wumpus' cave is represented as a grid of interconnected rooms.
2. The adventurer, controlled by the player, starts in a random empty room.
3. The adventurer's goal is to kill the Wumpus, find the gold, and return to the starting room with the escape rope.
4. Rooms can be empty or contain one of four types of "events" (described below).
5. The player receives "percepts" (messages) when the adventurer is close to an event.
6. Hazards include bottomless pits and super bats.
7. The gold is hidden in a hazard-free room.
8. The player must navigate through tunnels, move, and fire arrows to achieve the objective.

## Game Elements

### The Adventurer

- The player controls the adventurer.
- Actions: Move to adjacent rooms or fire arrows.
- The adventurer starts with three arrows.
- Arrow mechanics: Arrows continue until they hit a wall or travel through three rooms.
- Shooting the Wumpus with an arrow kills it.

### The Wumpus

- The Wumpus is initially asleep but can wake up due to player actions.
- Wake-up conditions: Adventurer entering the room or missing an arrow shot.
- If the Wumpus wakes up in the same room as the adventurer, the game ends with the adventurer's demise.
- If the Wumpus wakes up due to an arrow, it may move to a random empty room to evade capture.

### Hazards

- Two types of hazards: bottomless pits and super bats.
- Bottomless pits cause death when entered.
- Super bats transport the adventurer to random rooms, which can be dangerous.

### The Gold

- The gold is hidden in a hazard-free room.
- Entering this room automatically collects the gold.

### Percepts

- Percepts provide clues about nearby events.
- Examples: "You smell a terrible stench" (Wumpus), "You hear wings flapping" (Super bats).

## Program Requirements

- The program allows user interaction to play Hunt the Wumpus.
- The cave's grid size is specified as an initial input.
- Visualization of the grid with the adventurer's position is provided.
- Debug mode can be enabled with "true" input to reveal all game elements.
- User inputs include movement and arrow firing commands.
- Multiple classes (Room, Event, Wumpus, Bats, Pit, Gold) with polymorphism.
- Proper memory management to avoid memory leaks.
- Implementation of the Big 3 (copy constructor, copy assignment operator, destructor).
- Code organization into interface, implementation, and application with a Makefile.

## Enjoy the Hunt!

Have an adventurous time playing Hunt the Wumpus! Explore the cave, collect gold, and outsmart the Wumpus to emerge victorious.

# Hokm Emtiyazi – Multi-Set Scoring Version of Hokm Game

This project implements an advanced version of the traditional Persian card game **Hokm**, called **Hokm Emtiyazi**, using the C programming language. In contrast to the basic version, this version supports **multi-set play**, **match scoring**, and more **sophisticated AI logic** for simulating 4 players.

---

## Project Objectives

- Simulate a full-length **multi-round, multi-set Hokm match** between two teams of 2 players each.
- Add **tournament-style scoring** by tracking sets won by each team.
- Implement **turn-based decision-making logic** with team strategy awareness.
- Provide a detailed **step-by-step terminal view** of the game for observation.

---

## Files

| File              | Description                                                  |
| ----------------- | ------------------------------------------------------------ |
| `hokmEmtiazi.c` | Main entry point, game control loop for multiple sets        |
| `tabeEmtiazi.c` | Core logic: player AI, card evaluation, round winners        |
| `tabeEmtiazi.h` | Header file with shared structures and function declarations |

---

## Game Logic Overview

### 1.  Card Distribution

- 52 cards are shuffled randomly.
- Dealt to 4 players in two phases:
  - **First 5 cards**, then
  - **Remaining 8 cards** (after trump is selected)

### 2.  Trump Suit Selection (Hokm)

- Player 1 selects the trump suit from the first 5 cards.
- Trump (Hokm) overrides all other suits in determining hand winners.

### 3.  Player Strategy Logic

Each of the 4 players makes decisions using the following rules:

- **Follow the suit** led if possible.
- If not, and if holding trump cards, consider using one to win the hand.
- If winning is not possible, play the **weakest available card**.
- Each round is started by the **winner of the previous hand**.
- Cards are tracked by index to help in team coordination.

---

## Match Scoring System

- One **set** is complete when a team wins **7 hands**.
- After each set, scores are recorded using `setTeam1` and `setTeam2`.
- The game is played over **5 total sets**.
- At the end, the team with the most sets won is declared the winner.

---

## Terminal UI

- Terminal prints **each player’s played card** during rounds.
- **Player 1’s hand is shown** so user can follow progress.
- After each set, scores are shown:
  - Hands won per team
  - Sets won per team
- Between sets, the game resets automatically and starts again.

---

## How to Compile and Run

```bash
gcc hokmEmtiazi.c tabeEmtiazi.c -o hokm_emtiazi
./hokm_emtiazi
```

---

## Strategy Highlights

- Players must decide when to spend trump cards
- AI logic ensures no illegal moves (e.g., breaking suit)
- Players are stateless but follow fixed strategic rules

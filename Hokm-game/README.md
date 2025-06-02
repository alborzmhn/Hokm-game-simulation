# 4-Player Hokm Card Game

This project implements a complete 4-player version of the traditional Persian card game **Hokm (حکم)** using the C programming language. Players take turns playing cards according to official rules, and teams compete to win hands and ultimately the game.

---

## Project Objectives

- Implement the **full logic** of a 4-player Hokm game in a terminal environment
- Handle **card distribution**, **Hokm (trump suit) selection**, **round execution**, and **determining winners**
- Simulate **basic AI decision-making** for computer-controlled players
- Enforce **Hokm rules** such as **suit-following** and **trump suit** override

---

## Core Features

### Card Distribution & Hokm Selection

- Cards are **randomly shuffled and distributed** to 4 players
- Player 1 selects the **Hokm** (trump suit)
- Cards are dealt in **two phases**: first 5 cards, then the remaining 8

---

### Player Decision Logic

- Each player **follows the lead suit** if possible
- If unable to follow suit but holds **trump cards**, they may try to win the hand
- If winning is unlikely, the **weakest card** is played to conserve strength

---

### Determining Hand Winner

After 4 cards are played in a hand:

- The winner is determined based on:
  - **Lead suit** and highest rank
  - **Trump suit (Hokm)** overrides all other suits
- The team that first **scores 7 hands** wins the game

---

### Terminal UI

- Displays **Player 1’s hand**, currently **played cards**, and **team scores**
- Pauses for user input between plays to enable **step-by-step observation**

---

## Project Files

| File       | Description                                              |
| ---------- | -------------------------------------------------------- |
| `hokm.c` | Main logic: initializes game, deals cards, runs the game |
| `tabe.c` | Logic for card play, rounds, and winner determination    |
| `tabe.h` | Header file with structure and function declarations     |

---

## Compilation

```bash
gcc hokm.c tabe.c -o hokm
```

---

## Run the Program

```bash
./hokm
```

# 1D Cellular Automata

## What is a Cellular Automaton?
A **Cellular Automaton (CA)** is a discrete model studied in computational theory, mathematics, and complexity science. In simple terms, it consists of an array of cells that evolve over discrete time steps based on predefined rules. Each cell's next state depends on its current value and the values of its immediate neighbors.

For a deeper dive into Cellular Automata, check out [this resource](https://mathworld.wolfram.com/CellularAutomaton.html).

## Project Overview
This project simulates a **1D Cellular Automaton** based on an initial array of `1s` and `0s`. The evolution of the system is dictated by a **rule set**—a binary representation that determines how each new cell is generated.

At each step (or **generation**), the automaton applies the rule set to each cell, considering its left and right neighbors. This process continues iteratively, generating new arrays that form interesting patterns over time.

### Example
Given an initial array:

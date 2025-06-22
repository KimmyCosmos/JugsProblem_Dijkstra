# Jugs Problem - Dijkstra's Algorithm (C++)

This project solves the classic water jugs problem using Dijkstra's algorithm in C++. Given two jugs with capacities `Ca` and `Cb`, and a target amount `N`, the program finds the minimum-cost sequence of operations to reach exactly `N` gallons in jug B. The solution accounts for various operation costs (fill, empty, pour).

This project was completed as part of a data structures and algorithms course.

## Technologies
- C++
- Standard Template Library (STL)

## Key concepts
- Graph modeling of state transitions
- Dijkstra’s algorithm for shortest path
- Priority queue for efficient state selection
- Custom cost handling for actions

## How to compile and run

### Compile
```
g++ main.cpp Jug.cpp -o jugs_solver
```

### Run
```
./jugs_solver
```

The program will:
- Run sample test cases with predefined jug capacities, target, and costs.
- Output the minimum-cost sequence of steps or report an error if no solution exists.

## What I learned
- Modeling a problem as a graph of states and actions
- Applying Dijkstra’s algorithm for minimum-cost solutions
- Managing dynamic state space with priority queues
- Handling custom cost scenarios in pathfinding algorithms

// Jug.h
// Uses STL priority queue and vector to implement Dijkstra's algorithm.
// Compatible with C++14. Based on getting_started.cpp from assignment.

#ifndef JUG_H
#define JUG_H

#include <string>
#include <vector>

class Jug {
public:
    Jug(int, int, int, int, int, int, int, int, int);
    ~Jug();

    // Returns -1 if invalid input, 0 if no solution, 1 if solution found.
    int solve(std::string &solution);

private:
    struct State {
        int a, b;
        int dist;
        int prev;
        std::string action;
        bool visited;
        State() : a(0), b(0), dist(INT32_MAX), prev(-1), visited(false) {}
        State(int a, int b) : a(a), b(b), dist(INT32_MAX), prev(-1), visited(false) {}
    };

    int Ca, Cb, N;
    int cfA, cfB, ceA, ceB, cpAB, cpBA;
    std::vector<State> states;
    int total_states;

    int stateIndex(int a, int b) const;
    void getPath(int goalIndex, std::string &solution);
};

#endif

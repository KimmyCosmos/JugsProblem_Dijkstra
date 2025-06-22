#include "Jug.h"
#include <queue>
#include <sstream>
#include <limits>
#include <tuple>  // Required for std::make_tuple and std::get

Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA)
    : Ca(Ca), Cb(Cb), N(N), cfA(cfA), cfB(cfB), ceA(ceA), ceB(ceB), cpAB(cpAB), cpBA(cpBA) {
    // Defer state vector construction until solve() after input validation
}

Jug::~Jug() {}

int Jug::stateIndex(int a, int b) const {
    return a * (Cb + 1) + b;
}

int Jug::solve(std::string &solution) {
    // ✅ Validate inputs BEFORE resizing vector
    if (Ca <= 0 || Cb <= 0 || Ca > Cb || N > Cb || N < 0 || Cb > 1000 ||
        cfA < 0 || cfB < 0 || ceA < 0 || ceB < 0 || cpAB < 0 || cpBA < 0) {
        solution = "";
        return -1;
    }

    // ✅ Now safe to build graph
    total_states = (Ca + 1) * (Cb + 1);
    states.clear();
    states.resize(total_states);
    for (int a = 0; a <= Ca; ++a) {
        for (int b = 0; b <= Cb; ++b) {
            states[stateIndex(a, b)] = State(a, b);
        }
    }

    typedef std::pair<int, int> P;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    int start = stateIndex(0, 0);
    states[start].dist = 0;
    pq.push(std::make_pair(0, start));

    while (!pq.empty()) {
        P top = pq.top(); pq.pop();
        int idx = top.second;
        State &s = states[idx];
        if (s.visited) continue;
        s.visited = true;

        if (s.a == 0 && s.b == N) {
            getPath(idx, solution);
            return 1;
        }

        std::vector<std::tuple<int, int, std::string>> actions;

        actions.push_back(std::make_tuple(cfA, stateIndex(Ca, s.b), "fill A"));
        actions.push_back(std::make_tuple(cfB, stateIndex(s.a, Cb), "fill B"));
        actions.push_back(std::make_tuple(ceA, stateIndex(0, s.b), "empty A"));
        actions.push_back(std::make_tuple(ceB, stateIndex(s.a, 0), "empty B"));

        int pourAB = std::min(s.a, Cb - s.b);
        actions.push_back(std::make_tuple(cpAB,
                          stateIndex(s.a - pourAB, s.b + pourAB), "pour A B"));

        int pourBA = std::min(s.b, Ca - s.a);
        actions.push_back(std::make_tuple(cpBA,
                          stateIndex(s.a + pourBA, s.b - pourBA), "pour B A"));

        for (size_t i = 0; i < actions.size(); ++i) {
            int c = std::get<0>(actions[i]);
            int next = std::get<1>(actions[i]);
            std::string act = std::get<2>(actions[i]);

            if (states[next].dist > s.dist + c) {
                states[next].dist = s.dist + c;
                states[next].prev = idx;
                states[next].action = act;
                pq.push(std::make_pair(states[next].dist, next));
            }
        }
    }

    solution = "";
    return 0;
}

void Jug::getPath(int goalIndex, std::string &solution) {
    std::vector<std::string> steps;
    int curr = goalIndex;
    while (states[curr].prev != -1) {
        steps.push_back(states[curr].action);
        curr = states[curr].prev;
    }

    std::ostringstream oss;
    for (int i = steps.size() - 1; i >= 0; --i) {
        oss << steps[i] << "\n";
    }
    oss << "success " << states[goalIndex].dist;
    solution = oss.str();
}

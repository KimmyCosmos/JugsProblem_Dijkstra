#include <iostream>
#include <string>
#include "Jug.h"

using namespace std;

int main() {
    string solution;

    // Test 1: sample test case
    Jug head(3, 5, 4, 1, 2, 3, 4, 5, 6);
    if (head.solve(solution) != 1) {
        cout << "Error 3" << endl;
    } else {
        cout << solution << endl << endl;
    }

    // Test 2: another sample test case
    solution.clear();
    Jug head2(3, 5, 4, 1, 1, 1, 1, 1, 2);
    if (head2.solve(solution) != 1) {
        cout << "Error 3" << endl;
    } else {
        cout << solution << endl;
    }

    return 0;
}

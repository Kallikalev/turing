//
// Created by Kalev Martinson on 7/3/24.
//

#include "MachineMaker.h"
#include <iostream>

int MachineMaker::getTransition(int n, int states) {
    int write = n % 2;
    int direction = (n / 2) % 2;
    int next = n / 4;
    return (next << 2) + (write << 1) + direction;
}

void MachineMaker::makeAllMachines(std::vector<TuringMachine>& machines, int n) {
    int numMachines = (int)pow(4 * n + 4, 2 * n);
    machines.resize(numMachines, TuringMachine(n));
    int uniqueTransitions = 4 * n + 4;
    // initialize all machines
    for (int i = 0; i < numMachines; i++) {
        for (int j = 0; j < n * 2; j++) {
            int newTransition = getTransition((i / (int)pow(uniqueTransitions, j)) % uniqueTransitions,n);
            machines[i].transitions[j] = newTransition;
        }
        if (i % 100000 == 0) {
            std::cout << "Created machine " + std::to_string(i) << "/" + std::to_string(numMachines) << std::endl;
        }
    }
}
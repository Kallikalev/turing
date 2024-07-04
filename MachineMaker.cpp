//
// Created by Kalev Martinson on 7/3/24.
//

#include "MachineMaker.h"
#include <iostream>

#define TRANSITION_BITS 5

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
        for (int j = n * 2 - 1; j >= 0; j--) {
            int newTransition = getTransition((i / (int)pow(uniqueTransitions, j)) % uniqueTransitions,n);
            machines[i].transitions = machines[i].transitions << TRANSITION_BITS;
            machines[i].transitions += newTransition;
        }
        if (i % 1000000 == 0) {
            std::cout << "Created machine " + std::to_string(i) << "/" + std::to_string(numMachines) << std::endl;
        }
    }
}
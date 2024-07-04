//
// Created by Kalev Martinson on 7/2/24.
//

#ifndef TURING_TURINGMACHINE_H
#define TURING_TURINGMACHINE_H

#include <vector>
#include <array>

class TuringMachine {
public:
    int transitions = 0; // bitmap, next state | write | direction
    int state = 0;
    int position = 0;
    int iterations = 0;
    int numStates;

    bool simulate(std::vector<bool>& tapeRight, std::vector<bool>& tapeLeft);
    long tapeToNumber();

    explicit TuringMachine(int numStates);
};

#endif //TURING_TURINGMACHINE_H

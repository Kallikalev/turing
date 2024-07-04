//
// Created by Kalev Martinson on 7/2/24.
//

#ifndef TURING_TURINGMACHINE_H
#define TURING_TURINGMACHINE_H

#include <vector>
#include <array>

class TuringMachine {
public:
    std::vector<int> transitions; // bitmap, next state | write | direction
    int state = 0;
    int position = 0;
    int iterations = 0;
    std::vector<bool> tapeRight;
    std::vector<bool> tapeLeft;
    int numStates;

    bool simulate();
    long tapeToNumber();

    explicit TuringMachine(int numStates);
};

#endif //TURING_TURINGMACHINE_H

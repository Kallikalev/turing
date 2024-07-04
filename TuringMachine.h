//
// Created by Kalev Martinson on 7/2/24.
//

#ifndef TURING_TURINGMACHINE_H
#define TURING_TURINGMACHINE_H

#include <vector>

class TuringMachine {
public:
    std::vector<int> transitions; // bitmap, next state | write | direction
    int state = 0;
    int position = 0;
    int startShift = 0;
    int iterations = 0;
    std::vector<bool> tapeRight = {false};
    std::vector<bool> tapeLeft = {false};

    bool simulate();
    long tapeToNumber();
};

#endif //TURING_TURINGMACHINE_H

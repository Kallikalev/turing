//
// Created by Kalev Martinson on 7/2/24.
//

#ifndef TURING_TURINGMACHINE_H
#define TURING_TURINGMACHINE_H

#include <vector>

struct Transition {
    int nextState;
    int write;
    int direction;
};

class TuringMachine {
public:
    std::vector<Transition> transitions;
    int state = 0;
    int position = 0;
    int startShift = 0;
    int iterations = 0;
    std::vector<bool> tape = {false};

    bool simulate();
};

#endif //TURING_TURINGMACHINE_H

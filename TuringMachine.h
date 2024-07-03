//
// Created by Kalev Martinson on 7/2/24.
//

#ifndef TURING_TURINGMACHINE_H
#define TURING_TURINGMACHINE_H

#include <vector>

struct Transition {
    int nextState;
    bool direction;
    bool write;
};

class TuringMachine {
public:
    std::vector<std::pair<Transition, Transition>> transitions;
    int state = 0;
    int position = 0;
    std::vector<bool> tape = {false};

    bool simulate();
};

#endif //TURING_TURINGMACHINE_H

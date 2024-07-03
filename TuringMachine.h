//
// Created by Kalev Martinson on 7/2/24.
//

#ifndef TURING_TURINGMACHINE_H
#define TURING_TURINGMACHINE_H

#include <vector>

class TuringMachine {
    struct Transition {
        int nextState;
        bool direction;
        bool write;
    };

    bool halted;
    std::vector<Transition> transitions;
    int state;
    int position;
    std::vector<bool> tape;

    bool simulate();
};

#endif //TURING_TURINGMACHINE_H

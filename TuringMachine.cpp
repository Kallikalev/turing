//
// Created by Kalev Martinson on 7/2/24.
//
#include "TuringMachine.h"

bool TuringMachine::simulate() {
    if (state == -1) {
        return true;
    }
    Transition t = tape[position] ? transitions[state].second : transitions[state].first;
    tape[position] = t.write;
    state = t.nextState;
    if (t.direction) { // right
        if (position == tape.size() - 1) {
            tape.push_back(false);
        }
        position++;
    } else { // left
        position--;
        if (position < 0) { // don't move when we're at the left edge of the tape
            position = 0;
        }
    }
    return state == -1;
}


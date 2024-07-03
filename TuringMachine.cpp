//
// Created by Kalev Martinson on 7/2/24.
//
#include "TuringMachine.h"

bool TuringMachine::simulate() {
    if (state == -1) {
        return true;
    }

    Transition t = transitions[state * 2 + tape[position]];
    tape[position] = t.write;
    state = t.nextState;
    if (t.direction == 1) { // right
        if (position == tape.size() - 1) { // expand the tape when we reach the edge
            tape.push_back(false);
        }
        position++;
    } else { // left
        if (position == 0) { // expand the tape when we reach the edge
            tape.insert(tape.begin(),false);
            startShift++; // keep track of where our starting position is
        } else {
            position--;
        }
    }
    return state == -1;
}


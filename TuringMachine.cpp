//
// Created by Kalev Martinson on 7/2/24.
//
#include "TuringMachine.h"

bool TuringMachine::simulate() {
    if (state == -1) {
        return true;
    }

    int transition = transitions[state * 2 + tape[position]];
    tape[position] = (transition & 0b10) >> 1;
    state = transition >> 2;
    if ((transition & 0b1) == 1) { // right
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
    iterations++;
    return state == -1;
}

// We interleave the tape, beginning with the start position, then one before it,
// then one after it, then two before it, then two after it, and so on.
// We convert this interleaving into a natural number via binary with the smallest power on the left,
// rather than the common convention of the smallest on the right
long TuringMachine::tapeToNumber() {
    long num = 0;
    for (int i = 0; i < tape.size(); i++) {
        if (i < startShift) {
            int placesLeft = startShift - i;
            num += (long)tape[i] << (placesLeft * 2 - 1);
        } else {
            int placesRight = i - startShift;
            num += (long)tape[i] << placesRight * 2;
        }
    }
    return num;
}


//
// Created by Kalev Martinson on 7/2/24.
//
#include "TuringMachine.h"

bool TuringMachine::simulate() {
    if (state == -1) {
        return true;
    }
    int tapeData = position >= 0 ? tapeRight[position] : tapeLeft[-position - 1];
    int transition = transitions[state * 2 + tapeData];
    if (position >= 0) {
        tapeRight[position] = (transition & 0b10) >> 1;
        if ((transition & 0b1) == 1) { // right
            if (position == tapeRight.size() - 1) { // expand the tape when we reach the edge
                tapeRight.push_back(false);
            }
            position++;
        } else { // left
            position--;
        }
    } else {
        tapeLeft[-position - 1] = (transition & 0b10) >> 1;
        if ((transition & 0b1) == 1) { // right
            position++;
        } else { // left
            if ((-position - 1) == tapeLeft.size() - 1) { // expand the tape when we reach the edge
                tapeLeft.push_back(false);
            }
            position--;
        }
    }
    state = transition >> 2;
    iterations++;
    return state == -1;
}

// We interleave the tape, beginning with the start position, then one before it,
// then one after it, then two before it, then two after it, and so on.
// We convert this interleaving into a natural number via binary with the smallest power on the left,
// rather than the common convention of the smallest on the right
long TuringMachine::tapeToNumber() {
    long num = 0;
    for (int i = 0; i < tapeRight.size(); i++) {
        num += (long)tapeRight[i] << i * 2;
    }
    for (int i = 0; i < tapeLeft.size(); i++) {
        int placesLeft = i + 1;
        num += (long)tapeLeft[i] << (placesLeft * 2 - 1);
    }
    return num;
}


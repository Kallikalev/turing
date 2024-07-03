//
// Created by Kalev Martinson on 7/3/24.
//

#include <stdexcept>
#include "Beaver.h"

int Beaver::busyBeaver(int n) {
    if (n < 1) {
        throw std::invalid_argument("Busy beaver is not defined for n < 1");
    }
    if (n > 5) {
        throw std::invalid_argument("Busy beaver is unknown for n > 5");
    }
    return beavers[n - 1];
}
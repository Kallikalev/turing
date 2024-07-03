//
// Created by Kalev Martinson on 7/3/24.
//

#ifndef TURING_MACHINEMAKER_H
#define TURING_MACHINEMAKER_H

#include <vector>
#include "TuringMachine.h"



class MachineMaker {
public:
    static std::vector<TuringMachine> makeAllMachines(int n);
private:
    static Transition getTransition(int n, int states);
};


#endif //TURING_MACHINEMAKER_H

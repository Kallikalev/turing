#include <iostream>
#include "TuringMachine.h"
#include "MachineMaker.h"
#include "Beaver.h"


int main() {
    int states = 3;
    std::vector<TuringMachine> allMachines = MachineMaker::makeAllMachines(states);

    for (int i = 0; i < allMachines.size(); i++) {
        TuringMachine& machine = allMachines[i];
        while (machine.state != -1 && machine.iterations <= Beaver::busyBeaver(states)) {
            machine.simulate();
        }
        if (i % 100000 == 0) {
            std::cout << "Simulated machine " + std::to_string(i)
            <<"/" + std::to_string(allMachines.size()) << std::endl;
        }
    }
    std::vector<int> haltTimes;
    for (int i = 0; i < Beaver::busyBeaver(states); i++) {
        haltTimes.push_back(0);
    }
    int numHalted = 0;
    for (auto & machine : allMachines) {
        numHalted += machine.state == -1;
        haltTimes[machine.iterations - 1]++;
    }
    std::cout << "Number that halt: " + std::to_string(numHalted) << std::endl;
    for (int i = 0; i < haltTimes.size(); i++) {
        std::cout << "Number that halt after " << std::to_string(i + 1) << " iterations: "
        << std::to_string(haltTimes[i]) << std::endl;
    }
    return 0;
}
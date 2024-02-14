#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

#include "utils.h"

int main(int argc, char **argv) {
    Parameters p = readInput(argc, argv);

    std::vector<NiggaBalls> niggas = readInputFile(p.inputFileName);

    std::vector<Definition> nodes = readDefinition(p.definitionFileName);
    
    runDecisionTree(nodes, niggas);

    printResults(p.outputFileName, niggas);

    return 0;    
}
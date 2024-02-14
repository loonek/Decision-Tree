#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>

#include "utils.h"

int main(int argc, char **argv) {
    Parameters p = readInput(argc, argv);

    std::vector<std::vector<float>> niggas = readInputFile(p.inputFileName);

    std::map<std::string, std::vector<std::vector<float>>> sortedNiggas;
    std::vector<Definition> nodes = readDefinition(p.definitionFileName, sortedNiggas);
    
    runDecisionTree(nodes, niggas, sortedNiggas);

    printResults(p.outputFileName, sortedNiggas);

    return 0;    
}
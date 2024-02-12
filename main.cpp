#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

#include "utils.h"

int main(int argc, char **argv) {
    Parameters p = readInput(argc, argv);

    std::vector<std::vector<float>> attributeValues;
    readInputFile(p.inputFileName, attributeValues);

    std::vector<Definition> nodes = readDefinition(p.definitionFileName);
    
    runDecisionTree();

    return 0;    
}
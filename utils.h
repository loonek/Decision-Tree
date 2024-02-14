#include <string>
#include <vector>
#include <sstream>
#include <fstream>

struct Parameters
{
    std::string inputFileName;
    std::string definitionFileName;
    std::string outputFileName;
};

struct Definition
{
    int index;
    std::string attribute;
    char op;
    float value;
    std::string trueLabel;
    std::string falseLabel;
    int trueIndex;
    int falseIndex;
};

struct NiggaBalls
{
    std::vector<float> attributes;
    std::string decision;
};


bool isNumber(const std::string& str);


Parameters readInput(int argc, char *argv[]);


std::vector<NiggaBalls> readInputFile(const std::string& inputFileName);


std::vector<Definition> readDefinition(const std::string& inputFileName);


void runDecisionTree(const std::vector<Definition>& nodes, std::vector<NiggaBalls>& niggas);


void printResults(const std::string& outputFileName, const std::vector<NiggaBalls>& niggas);
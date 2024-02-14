#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>

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


bool isNumber(const std::string& str);


Parameters readInput(int argc, char *argv[]);


std::vector<std::vector<float>> readInputFile(const std::string& inputFileName);


std::vector<Definition> readDefinition(const std::string& inputFileName, std::map<std::string, std::vector<std::vector<float>>>& sortedNiggas);


void runDecisionTree(const std::vector<Definition>& nodes, const std::vector<std::vector<float>>& niggas, std::map<std::string, std::vector<std::vector<float>>>& sortedNiggas);


void printResults(const std::string& outputFileName, std::map<std::string, std::vector<std::vector<float>>>& sortedNiggas);
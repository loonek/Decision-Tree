#include "utils.h"
#include "errorMessages.h"

bool isNumber(std::string& str) 
{
    bool dot = false;
    for (int i = 0; i < str.size(); i++) 
    { 
        if ((str.at(i) == '.' || str.at(i) == ',')  && dot == false)
        {
            dot = true;
        }
        else if ((str.at(i) == '.' || str.at(i) == ',') && dot == true)
        {
            return false;
        }
        else if (!std::isdigit(str[i]))
        {
            return false;
        }
    }

    if (str.size() == 1 && str[0] == '.') return false;

    return true;
}

Parameters readInput(int argc, char *argv[])
{
    Parameters p;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-i" && i + 1 < argc) {
            try
            {
                p.inputFileName = argv[i + 1];
            }
            catch(const std::exception& e)
            {
                std::cerr << "There's no correct parameter for your input file\n";
                printHelp();
            }    
        } else if (arg == "-t" && i + 1 < argc) {
            try
            {
                p.definitionFileName = argv[i + 1];
            }
            catch(const std::exception& e)
            {
                std::cerr << "There's no correct parameter for your decision file\n";
                printHelp();
            }
            
        } else if (arg == "-o" && i + 1 < argc) {
            try
            {
                p.outputFileName = argv[i + 1];
            }
            catch(const std::exception& e)
            {
                std::cerr << "There's no correct parameter for your output file\n";
                printHelp();
            }
        }
    }

    return p;
}

std::vector<NiggaBalls> readInputFile(const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        std::cerr << "Your input file destination(" << inputFileName << ") is incorrect.\n";
        exit(EXIT_FAILURE);
    }

    int n = 0;
    std::string line;

    if(std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string attributeName;

        while(iss >> attributeName)
        {
            if(attributeName == "%") break;
            n++;       
        }
    }

    
    std::vector<NiggaBalls> niggas;
    int r = 0, c = 0;

    while(std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        NiggaBalls niggaBall;
        std::string value;
        while (iss >> value)
        {
            c++;

            if(c > n)
            {
                tooMuchData(r + 2, c + 1, value);
            }
            if(isNumber(value))
            {
                niggaBall.attributes.push_back(std::stof(value));
            }
            else
            {
                wrongDataType(r + 2, c + 1, value);
            }
        }
        
        if(c < n)
        {
            notEnoughData(r + 2, c + 1);
        }

        c = 0;
        niggas.push_back(niggaBall);
    }

    inputFile.close();
    return niggas;
}

std::vector<Definition> readDefinition(const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        std::cerr << "Your input file destination(" << inputFileName << ") is incorrect.\n";
        exit(EXIT_FAILURE);
    }

    std::vector<Definition> nodes;
    std::string line;

    while(std::getline(inputFile, line))
    {        
        std::istringstream iss(line);
        std::string value;
        int count = 0;
        Definition node;
        
        if(iss >> value)
        {
            if(isNumber(value))
            {
                node.index = stoi(value);
                count++;
            }
            else
            {
                NotNumber(value, count + 1);
            }
        }
        if(iss >> value)
        {
            node.attribute = value;
            count++;
        }
        if(iss >> value)
        {
            if(value == "<" || value == ">")
            {
                node.op = value.at(0);
                count++;
            }
            else
            {
                wrongop(std::to_string(node.index), count + 1);
            }
        }
        if(iss >> value)
        {
            if(isNumber(value))
            {
                node.value = std::stof(value);
                count++;
            }
            else
            {
                NotNumber(std::to_string(node.index), count + 1);
            }
        }
        if(iss >> value)
        {
            if(isNumber(value))
            {
                node.falseIndex = stoi(value);
                count++;
            }
            else
            {
                node.falseLabel = value;
                node.falseIndex = -1;
                count++;
            }
        }
        if(iss >> value)
        {
            if(isNumber(value))
            {
                node.trueIndex = stoi(value);
                count++;
            }
            else
            {
                node.trueLabel = value;
                node.trueIndex = -1;
                count++;
            }
        }
        if(count < 6)
        {
            tooLittleData(std::to_string(node.index), count + 1);
        }
        else
        {
            nodes.push_back(node);
        }
    }
    return nodes;
}

void runDecisionTree(const std::vector<Definition>& nodes, std::vector<NiggaBalls>& niggas)
{
    for(int i = 0; i < niggas.size(); i++)
    {
        int n = 0;

        while(niggas[i].decision.empty())
        {
            if(nodes[n].op == '<')
            {
                if(niggas[i].attributes[n] < nodes[n].value)
                {
                    if(nodes[n].trueIndex == -1)
                    {
                        niggas[i].decision = nodes[n].trueLabel;
                    }
                    else
                    {
                        n = nodes[n].trueIndex;
                    }
                }
                else
                {
                    if(nodes[n].falseIndex == -1)
                    {
                        niggas[i].decision = nodes[n].falseLabel;
                    }
                    else
                    {
                        n = nodes[n].falseIndex;
                    }
                }
            }
            else
            {
                if(niggas[i].attributes[n] > nodes[n].value)
                {
                    if(nodes[n].trueIndex == -1)
                    {
                        niggas[i].decision = nodes[n].trueLabel;
                    }
                    else
                    {
                        n = nodes[n].trueIndex;
                    }
                }
                else
                {
                    if(nodes[n].falseIndex == -1)
                    {
                        niggas[i].decision = nodes[n].falseLabel;
                    }
                    else
                    {
                        n = nodes[n].falseIndex;
                    }
                }
            }
        }
    }
}

void printResults(const std::string& outputFileName, const std::vector<NiggaBalls>& niggas)
{
    std::ofstream outputFile(outputFileName);

    for(int i = 0; i < niggas.size(); i++)
    {
        for(int j = 0; j < niggas[i].attributes.size(); j++)
        {
            outputFile << niggas[i].attributes[j] << ", ";
        }
        outputFile << " = "<< niggas[i].decision << "\n";
    }
}
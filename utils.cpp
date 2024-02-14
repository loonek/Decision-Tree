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

std::vector<std::vector<float>> readInputFile(const std::string& inputFileName)
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

    
    std::vector<std::vector<float>> niggas;
    int r = 0, c = 0;

    while(std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::vector<float> dolgorapojebanaamplituda;
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
                dolgorapojebanaamplituda.push_back(std::stof(value));
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
        niggas.push_back(dolgorapojebanaamplituda);
    }

    inputFile.close();
    return niggas;
}

std::vector<Definition> readDefinition(const std::string& inputFileName, std::map<std::string, std::vector<std::vector<float>>>& sortedNiggas)
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
                sortedNiggas.emplace(value, std::vector<std::vector<float>>{});
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
                sortedNiggas.emplace(value, std::vector<std::vector<float>>{});
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

void runDecisionTree(const std::vector<Definition>& nodes, const std::vector<std::vector<float>>& niggas, std::map<std::string, std::vector<std::vector<float>>>& sortedNiggas) 
{
    for(int i = 0; i < niggas.size(); i++)
    {
        int n = 0;
        
        while(true)
        {
            if(nodes[n].op == '<')
            {
                if(niggas[i][n] > nodes[n].value)
                    {
                    if(nodes[n].trueIndex == -1)
                    {
                        sortedNiggas[nodes[n].trueLabel].push_back(niggas[i]);
                        break;
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
                        sortedNiggas[nodes[n].falseLabel].push_back(niggas[i]);
                        break;
                    }
                    else
                    {
                        n = nodes[n].falseIndex;
                    }
                }
            }
            else
            {
                if(niggas[i][n] < nodes[n].value)
                {
                    if(nodes[n].trueIndex == -1)
                    {
                        sortedNiggas[nodes[n].trueLabel].push_back(niggas[i]);
                        break;
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
                        sortedNiggas[nodes[n].falseLabel].push_back(niggas[i]);
                        break;
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

void printResults(const std::string& outputFileName, std::map<std::string, std::vector<std::vector<float>>>& sortedNiggas)
{
    std::ofstream outputFile(outputFileName);

    while(!sortedNiggas.empty())
    {
        std::string decision = sortedNiggas.begin()->first;
        outputFile << decision << ":\n";

        for(const auto& nigga : sortedNiggas)
        {
            if(nigga.first == decision)
            {
                for(int i = 0; i < nigga.second.size(); i++)
                {  
                    for(int j = 0; j < nigga.second[i].size(); j++)
                    {
                        outputFile << nigga.second[i][j] << " ";
                    }
                    outputFile << "\n";
                }
                outputFile << "\n";
            }
        }

        sortedNiggas.erase(decision);
    }
}
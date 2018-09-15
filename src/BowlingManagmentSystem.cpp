#include <../inc/BowlingManagmentSystem.hpp>
#include <fstream>
#include <iostream>

BowlingManagmentSystem::BowlingManagmentSystem()
{
}

void BowlingManagmentSystem::aboutTheProject()
{
    std::cout<<"To display results on the screen enter: ./Bowling results\n";
    std::cout<<"To display results on the screen and save them enter: ./Bowling results <fileName.txt>\n";
    std::cout<<"For more information check: https://github.com/CodersSchool777/bowling\n";
}

bool BowlingManagmentSystem::checkFirstGivenArgument(const std::string &firstArgument)
{
    if(firstArgument == "-h" || firstArgument == "--help")
        return true;
    else return false;
}

void BowlingManagmentSystem::showResultsOnTheMonitor(const std::string &firstArgument)
{
    Bowling bowling("../" + firstArgument);
    std::cout<<bowling;
}

void BowlingManagmentSystem::saveResultsInExternalFile(const std::string &firstArgument,
                                                       const std::string &secondArgument)
{
    Bowling bowling("../" + firstArgument);
    std::ofstream inFile("../save/" + secondArgument);
    inFile<<bowling;
}

void BowlingManagmentSystem::run(int argc, char* argv[])
{
    switch(argc)
    {
    case 2:                                                             //file direcory or help
        if(checkFirstGivenArgument(std::string(argv[1])))
            aboutTheProject();
        else showResultsOnTheMonitor(std::string(argv[1]));
        break;
    case 3:                                                             //optional file.txt
        showResultsOnTheMonitor(std::string(argv[1]));
        saveResultsInExternalFile(std::string(argv[1]), std::string(argv[2]));
        break;
    default:
        std::cout<<"Invalid number of given parameters"<<std::endl;
        break;
    }
}

BowlingManagmentSystem::~BowlingManagmentSystem()
{
}

#include "Logger.h"
#include<fstream>
#include <iostream>
Logger::Logger()
{
    logs={};

}
void Logger::log(std::string s)
{
    logs.push_back(s);
}

void Logger::saveToFile(std::string p)
{
    std::ofstream reader (p);

    for(std::string s:logs)
    {
        reader<<s<<std::endl;
    }
    reader.close();
}
int Logger::getSize()
{
    return logs.size();
}

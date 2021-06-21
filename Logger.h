#ifndef LOGGER_H
#define LOGGER_H
#include<vector>
#include<string>

class Logger
{
    public:
        Logger();

        void log(std::string s);
        void saveToFile(std::string p);
        int getSize();



    private:
         std::vector <std::string> logs;

};

#endif // LOGGER_H

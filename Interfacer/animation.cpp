#include "animation.h"
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <vector>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::flush;

Animation::Animation(int spd, std::string txt, int color):  speed(spd), text(txt), colour(color)
{

}

bool replace(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void Animation::Draw(std::map<std::string, std::string> vars)
{
    if(text == "break")
        std::cout<<"\r\n";
    else
    {
        std::vector<std::string> keys;
        for(std::map<std::string,std::string>::iterator it = vars.begin(); it != vars.end(); ++it) {
          keys.push_back(it->first);
        }
        for(std::string s : keys)
        {
            if(text.find(s))
                replace(text,s,vars[s]);
        }

        if(colour != 0)
            std::cout<<"\033["+std::to_string(colour)+"m";
        if(speed>0)
        {
            for(char c : text)
            {
                std::cout<<c<<flush;
                sleep_for(milliseconds(speed*10));
            }
        }
        else
            std::cout<<text<<flush;

        std::cout<<"\033[0m";
        std::cout<<"\033[39m";
    }
}

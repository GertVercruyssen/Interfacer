#ifndef OPTION_H
#define OPTION_H

#include <string>

class Option
{
public:
    Option(std::string menuname, std::string txt);
    void Draw();
    std::string menu;
    std::string text;
};

#endif // OPTION_H

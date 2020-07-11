#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "option.h"
#include "animation.h"


class Menu
{
public:
    Menu(std::string name, bool glitched, bool voice);
    void AddOption(const Option& opt);
    void AddAnimation(const Animation& opt);
    void Draw(std::map<std::string, std::string> vars);
    std::string GetMenuForOption(int option);
    bool isInput = false;
    std::vector<Option>* optionslist;

private:
    std::vector<Animation>* animationslist;
};

#endif // MENU_H

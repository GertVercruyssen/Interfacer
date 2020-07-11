#include "menu.h"
#include <iostream>

Menu::Menu(std::string name, bool glitched, bool voice)
{
    optionslist = new std::vector<Option> ();
    animationslist = new std::vector<Animation> ();
}

void Menu::AddOption(const Option& opt)
{
    optionslist->push_back(opt);
}
void Menu::AddAnimation(const Animation& ani)
{
    animationslist->push_back(ani);
}
void Menu::Draw(std::map<std::string, std::string> vars)
{
    for (auto &anim : *animationslist)
        anim.Draw(vars);

    std::cout<< "\r\n";
    int teller=0;
    for (auto &opt : *optionslist)
    {
        teller++;
        std::cout<<teller<<':';
        opt.Draw();
    }

    std::cout<< "\r\n";
}

std::string Menu::GetMenuForOption(int option)
{
    if(option > optionslist->size())
        return "error";
    return optionslist->at(option-1).menu;
}

#include "script.h"
#include <fstream>
#include <iostream>
#include <string>
#include <forward_list>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

Script::Script(char* filepath)
{
    menusptr = new std::map<std::string, Menu*>();
    Menu* currentmenuptr;
    string line;
    fstream myfile (filepath);
    if(myfile.is_open())
    {
        while (getline(myfile,line))
        {
            vector<string> results = explode(line, ';');
            if(results.size() > 0)
            {
                if(results[0] == "menu")
                {
                    currentmenuptr = new Menu(results[1],results[2]=="true",results[3]=="true");
                    menusptr->insert({results[1],currentmenuptr});
                }
                if(results[0] == "animation")
                {
                    if(results.size() == 4)
                        currentmenuptr->AddAnimation(*new Animation(std::stoi(results[1]),results[2],std::stoi(results[3])));
                    else
                        currentmenuptr->AddAnimation(*new Animation(std::stoi(results[1]),results[2]));
                }
                if(results[0] == "option")
                {
                    if(results[2][0] == '$')
                        currentmenuptr->isInput = true;
                    currentmenuptr->AddOption( *new Option(results[1],results[2]));
                }
            }
        }
    }
}
void Script::Run()
{
    map<string, string> vars;
    menusptr->at("home")->Draw(vars);
    Menu* currentmenu = menusptr->at("home");
    int inputnumber=0;
    string inputtext;
    while(inputnumber!=9)
    {
        if(!currentmenu->isInput)
        {
            std::cin >> inputnumber;
        }
        else
        {
            std::cin >> inputtext;
            inputnumber=1;
            vars.insert( {currentmenu->optionslist->at(0).text, inputtext});
        }


        if(currentmenu->GetMenuForOption(inputnumber) == "error")
        {
            cout << "invalid input";
            cout<< "\r\n";
        }
        else
        {
            cout << "\033[2J\033[1;1H";
            currentmenu = menusptr->at(currentmenu->GetMenuForOption(inputnumber));
            currentmenu->Draw(vars);
        }
    }

    std::cout<< "\r\n";

}

const vector<string> Script::explode(const string& s, const char& c)
{
    string buff{""};
    vector<string> v;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);

    return v;
}


#ifndef SCRIPT_H
#define SCRIPT_H
#include <string>
#include <forward_list>
#include "menu.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

class Script
{
public:
    Script(char* filepath);
    void Run();

protected:
    std::map<std::string, Menu*>* menusptr;
private:
    const std::vector<std::string> explode(const std::string& s, const char& c);

};

#endif // SCRIPT_H

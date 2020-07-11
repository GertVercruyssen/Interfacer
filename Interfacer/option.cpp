#include "option.h"
#include <iostream>

Option::Option(std::string menuname, std::string txt) : menu(menuname), text(txt)
{

}
void Option::Draw()
{
    if(text[0] != '$')
        std::cout<<text<<"     ";
}

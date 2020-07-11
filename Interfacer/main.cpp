#include <iostream>
#include "script.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Error no file given, opening default";
        cout << "\r\n";

        Script* scriptptr = new Script("/home/gert/Desktop/script.txt");
        scriptptr->Run();

        cin.get();
    }
    else
    {
        //cout << "Opening file: ";
        //cout<< argv[1];
        cout << "\r\n";

        Script* scriptptr = new Script(argv[1]);
        scriptptr->Run();

        cout << "\r\n";
        cout<< "Script has ended, press any key to exit";
        cout << "\r\n";
        cin.get();
    }
}

#include <iostream>
#include <string>
#include <sstream>
#include "gametypes.h"

using std::cout;
using std::cin;
using std::flush;
using std::string;

int main()
{
    string choice;
    int choiceNum;
    cout << "Tic Tac Toe!\nYou Vs. Computer (1) or\nYou Vs. Another Player (2)\n> ";

    cin >> choice;
    std::istringstream iss (choice);
    iss >> choiceNum;

    switch (choiceNum)
    {
        case 1:
        {
            computer();
            // TODO: Implements Computer!
            break;
        }
        case 2:
        {
            player();
            break;
        }
        default:
        {
            cout << "Assuming against Player...\n" << flush;
            player();
            break;
        }
    }
}

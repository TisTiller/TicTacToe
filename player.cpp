#include "gametypes.h"
#include <iostream>

using std::cout;
using std::cin;
using std::flush;

void player()
{
    cout << "Decide who is player one (Y), and who is player 2 (Y).\n" << flush;
    Board gameboard;
    gameboard.initBoard();
    gameboard.showBoard();

    bool gameFinished = false;
    int turn = 1;

    while (!gameFinished)
    {
        if (turn == 1)
        {
            cout << "Player 1's turn.\n" << flush;
        } else if (turn == 2)
        {
            cout << "Player 2's turn.\n" << flush;
        }

        while (true)
        {
           int column, row;

            cout << "Column: ";
            cin >> column;
            cout << "Row: ";
            cin >> row;

            int success = gameboard.setBoard(turn, column-1, row-1);
            // It takes 1 because the first column and row are at 0.
            if (success == 0)
            {
                break;
            } else
            {
                cout << "Already Taken, Please try Again.\n";
            }
        }

        gameboard.showBoard();
        int finished = gameboard.checkBoard();
        if (finished == 1)
        {
            cout << "Player " << turn << " wins!\n" << flush;
            break;
        } else if (finished == 2)
        {
            cout << "Stalemate\n" << flush;
            break;
        } else
        {
            if (turn == 1)
            {
                turn = 2;
            } else
            {
                turn = 1;
            }
        }


    }
}

#include "gametypes.h"
#include <iostream>

using std::flush;
using std::cout;

void Board::initBoard()
{
    for (int x=0; x<3; ++x)
    {
        for (int y=0; y<3; ++y)
        {
            board [x][y] = -((x+5)*(y*2+3));
        }
    }
}

int Board::setBoard(int player, int xcoord, int ycoord)
{
    if (board[xcoord][ycoord] > 0)
    {
        return 1;
    }
    board[xcoord][ycoord] = player;
    return 0;
}

int Board::checkBoard()
{
    // Checks For Vertical Combos
    for (int x=0; x<3; ++x)
    {
        if (board[x][0] == board[x][1] && board[x][1] == board[x][2])
        {
            return 1;
        }
    }

    // Checks For Horizontal Combos
    for (int y=0; y<3; ++y)
    {
        if (board[0][y] == board[1][y] && board[1][y] == board[2][y])
        {
            return 1;
        }
    }

    // Checks the two Diagonal Combos
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }

    for (int x=0; x<3; ++x)
    {
        for (int y=0; y<3; ++y)
        {
            if (board [x][y] > 0)
            {
                // If this happens, there is space left to play.
                return 0;
            }
        }
    }
    // If this happens, there are no spaces left. Stalemate.
    return 2;
}

void Board::showBoard()
{
    cout << " 1 2 3 \n" << flush;
    cout << "_______\n" << flush;
    for (int y=0; y<3; ++y)
    {
        cout << "|" << flush;
        for (int x=0; x<3; ++x)
        {
            switch (board [x][y])
            {
            case 1:
                cout << "X" << flush;
                break;
            case 2:
                cout << "O" << flush;
                break;
            default:
                cout << " " << flush;
                break;
            }
            cout << "|" << flush;
        }
        cout << "\n" << flush;
    }
}

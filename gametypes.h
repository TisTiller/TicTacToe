#ifndef gametypes_h
#define gametypes_h

void computer();
void player();

class Board {
    int board [3][3];

public:
    void initBoard();
    int setBoard(int player, int xcoord, int ycoord);
    int checkBoard();
    void showBoard();

};

#endif
// gametypes_h

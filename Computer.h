//
// Created by abdel on 12/22/2022.
//

#ifndef ASSIGNMENT_3_COMPUTER_H
#define ASSIGNMENT_3_COMPUTER_H
using namespace std;
#include <bits/stdc++.h>
#define  sizeOfBoard 5
class Computer {
public:
    void bestMove(int player_num , string board[sizeOfBoard][sizeOfBoard]);
    int minimax (string board[sizeOfBoard][sizeOfBoard] , int depth , bool isMAX , int alpha=-10000 , int beta= 10000);
    int game_finished(string board[sizeOfBoard][sizeOfBoard]);
};


#endif //ASSIGNMENT_3_COMPUTER_H

//
// Created by abdel on 12/15/2022.
//
#ifndef ASSIGNMENT_3_PLAYERS_H
#define ASSIGNMENT_3_PLAYERS_H
#include <bits/stdc++.h>
using namespace std;
#define  sizeOfBoard 5

class players {
public:
    string rockets[sizeOfBoard-2];
    players();
    int playerChoice(int player_num);
    bool validCell(int player_num ,int rocket_number ,string board[sizeOfBoard][sizeOfBoard]);
    bool game_over(string board[sizeOfBoard][sizeOfBoard],int player_num);
    bool ValidMove(string board[sizeOfBoard][sizeOfBoard] , int player_number);



};


#endif //ASSIGNMENT_3_PLAYERS_H

//
// Created by abdel on 12/22/2022.
//

#include "Computer.h"


void Computer::bestMove(int player_num, string (*board)[5]) {
    int score , bestScore = -100000 , rocket_num ;
    for (int i = 1; i < sizeOfBoard-1; ++i) {
        for (int j = 0; j < sizeOfBoard; ++j) {
            if (board[i][j]==">"){

                if (j+1<sizeOfBoard && board[i][j+1]=="_") {
                    swap(board[i][j+1] , board[i][j]);
                    score = minimax(board , 2 , false );
                    swap(board[i][j+1] , board[i][j]);
                }
                else if (j+2<sizeOfBoard && board[i][j+2]=="_") {
                    swap(board[i][j+2] , board[i][j]);
                    score = minimax(board , 1 , false);
                    swap(board[i][j+2] , board[i][j]);
                }
                else
                    continue;
                if (score > bestScore) {
                    bestScore = score;
                    rocket_num = i;
                }
            }
        }
    }
    for (int i = 0; i < sizeOfBoard; ++i) {
        if (board[rocket_num][i] == ">") {
            if (board[rocket_num][i+1] == "_" && i+1<sizeOfBoard) {
                swap(board[rocket_num][i + 1], board[rocket_num][i]);
                break;
            }
            else {
                swap(board[rocket_num][i + 2], board[rocket_num][i]);
                break;
            }
        }
    }
}

int Computer::game_finished(string (*board)[5]) {
    bool not_finished = false ;
        for (int i = 1; i < sizeOfBoard-1; ++i) {
            if (board[sizeOfBoard-1][i]!="v"){
                not_finished = true;
                break;
            }

        }
        if (!not_finished)
            return -1;

    not_finished = false;
        for (int i = 1; i < sizeOfBoard-1; ++i) {
            if (board[i][sizeOfBoard-1]!=">") {
                not_finished = true;
                break;
            }
        }
        if (!not_finished)
            return 1;

        return 0;
}

int Computer::minimax(string (*board)[5], int depth, bool isMAX , int alpha , int beta) {
    if (game_finished(board) == 1)
        return 1000-depth;

    if (game_finished(board) == -1)
        return -1000+depth;

    if (isMAX) {
        int score = -10000;
        for (int i = 1; i < sizeOfBoard-1; ++i) {
            for (int j = 0; j < sizeOfBoard; ++j) {
                if (board[i][j]==">"){

                    if (j+1<sizeOfBoard && board[i][j+1]=="_") {
                        swap(board[i][j+1] , board[i][j]);
                        score = max(score ,minimax(board , depth+2 , false , alpha ,beta));
                        swap(board[i][j+1] , board[i][j]);
                    }
                    else if (j+2<sizeOfBoard && board[i][j+2]=="_") {
                        swap(board[i][j+2] , board[i][j]);
                        score = max(score ,minimax(board , depth+1  , false , alpha ,beta));
                        swap(board[i][j+2] , board[i][j]);
                    }
                    else {
                        continue;
                    }
                    alpha = max(alpha , score);
                    if (beta <= alpha)
                        return score;
                }
            }
        }
        return score;
    }
    else {
        int score = 10000;
        for (int i = 0; i < sizeOfBoard; ++i) {
            for (int j = 1; j < sizeOfBoard-1; ++j) {
                if (board[i][j]=="v"){

                    if (i+1<sizeOfBoard && board[i+1][j]=="_") {
                        swap(board[i+1][j] , board[i][j]);
                        score = min(score ,minimax(board , depth+2 , true));
                        swap(board[i+1][j] , board[i][j]);
                    }
                    else if (i+2<sizeOfBoard && board[i+2][j]=="_") {
                        swap(board[i+2][j] , board[i][j]);
                        score = min(score ,minimax(board , depth+1  , true));
                        swap(board[i+2][j] , board[i][j]);
                    }
                    else {
                        continue;
                    }
                    beta = min(beta , score);
                    if (beta <= alpha)
                        return score;
                }
            }
        }
        return score;
    }
}



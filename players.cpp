//
// Created by abdel on 12/15/2022.
//

#include "players.h"


players::players() {

}

int players::playerChoice(int player_num) {
    string rocket, move;
    cout << "\n\t\tthis your turn player "<<player_num<<"\n";

    cout << "Choose the rocket you want to move:";
    cin >> rocket;
    while (true) {
        if (rocket >= "1" && rocket <= to_string(sizeOfBoard - 2) && rocket.length() == 1)
            break;
        cout << "you don't have this number of rocket, try again\n";
        rocket = "";
        cout << "Choose the rocket you want to move:";
        cin >> rocket;
    }
    return stoi(rocket);
}

bool players::validCell(int player_num,int rocket_number ,string board[sizeOfBoard][sizeOfBoard]) {
    if (player_num==1) {
        for (int i = 0; i < sizeOfBoard; ++i) {
            if (board[i][rocket_number]=="v"){

                if (board[i+1][rocket_number]=="_" && i+1< sizeOfBoard) {
                    swap(board[i + 1][rocket_number],board[i ][rocket_number]);
                    break;
                }

                else if (board[i+1][rocket_number]!="_" && board[i+2][rocket_number]=="_" && i+2< sizeOfBoard) {
                    swap(board[i + 2][rocket_number],board[i][rocket_number]);
                    break;
                }

                else {
                    cout<<"you can't move this rocket, try another one\n";
                    return false;
                }
            }
        }
    }
    else if (player_num==2) {
        for (int i = 0; i < sizeOfBoard; ++i) {
            if (board[rocket_number][i]==">") {
                if (board[rocket_number][i+1]=="_" && i+1<sizeOfBoard){
                    swap(board[rocket_number][i+1],board[rocket_number][i]);
                    break;
                }

                else if (board[rocket_number][i+1]!="_" && board[rocket_number][i+2]=="_" && i+2<sizeOfBoard) {
                    swap(board[rocket_number][i+2],board[rocket_number][i]);
                    break;
                }

                else {
                    cout<<"you can't move this rocket, try another one\n";
                    return false;
                }
            }
        }
    }
    return true;
}

bool players::game_over(string board[sizeOfBoard][sizeOfBoard],int player_num) {
    if (player_num==1) {
        for (int i = 1; i < sizeOfBoard-1; ++i) {
            if (board[sizeOfBoard-1][i]!=rockets[i-1])
                return false;
        }
        return true;
    }
    else {
        for (int i = 1; i < sizeOfBoard-1; ++i) {
            if (board[i][sizeOfBoard-1]!=rockets[i-1])
                return false;
        }
        return true;
    }
}

bool players::ValidMove(string (*board)[5], int player_number) {
    if (player_number== 1) {
        for (int i = 1; i < sizeOfBoard-1; ++i) {
            for (int j = 0; j < sizeOfBoard; ++j) {
                if (board[j][i]=="v") {
                    if ((board[j+1][i] == "_" && j + 1 < sizeOfBoard) || (board[j+2][i ] == "_" && j + 2 < sizeOfBoard)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    else {
        for (int i = 1; i < sizeOfBoard-1; ++i) {
            for (int j = 0; j < sizeOfBoard; ++j) {
                if (board[i][j]==">")
                    if ((board[i][j+1]=="_"&&j+1<sizeOfBoard) || (board[i][j+2]=="_"&&j+2<sizeOfBoard))
                        return true;
            }
        }
    }
    return false;
}
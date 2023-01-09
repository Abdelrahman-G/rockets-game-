#include "players.h"
#include "Computer.h"
string board[sizeOfBoard][sizeOfBoard];
bool turn = true;
players player1 ,player2;
Computer computer ;
void setBoard() {
    board[0][0] ="X";
    board[0][sizeOfBoard - 1] ="X";
    board[sizeOfBoard - 1][0] =" X";
    board[sizeOfBoard - 1][sizeOfBoard - 1] ="X";
    for (int i = 0; i < sizeOfBoard-2; ++i) {
        player1.rockets[i] = "v";
    }
    for (int i = 0; i < sizeOfBoard-2; ++i) {
        player2.rockets[i] = ">";
    }
    for (int i = 1; i < sizeOfBoard-1; ++i) {
        board[0][i]=player1.rockets[i - 1];
    }
    for (int i = 1; i < sizeOfBoard-1; ++i) {
        board[i][0]=player2.rockets[i - 1];
    }
    for (auto & i : board) {
        for (auto & j : i) {
            if (j.empty())
                j="_";
        }
    }
}

void printBoard() {
    for (auto & i : board) {
        for (auto & j : i) {
            cout<<setw(3)<<j<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    setBoard();
    while (true) {
        string game_choice;
        cout<<"1-play with two players \n"
              "2-play against computer \n";
        cout<<"enter your choice :";
        cin>>game_choice;
        if (game_choice=="1") {
            printBoard();
            while(true) {
                int choice;
                if (turn) {
                    if (!player1.ValidMove(board ,1)) {
                        cout<<"sorry player 1, you don't have any valid moves\n";
                        turn = false;
                        continue;
                    }
                    choice = player1.playerChoice(1);
                    while (true) {
                        if (player1.validCell(1, choice, board))
                            break;
                        choice = player1.playerChoice(1);
                    }

                    if (player1.game_over(board, 1)) {
                        cout << "CONGRATS PLAYER 1, YOU HAVE WON!!\n";
                        printBoard();
                        exit(0);
                    }
                }
                if (!turn){
                    if (!player2.ValidMove(board ,2)) {
                        cout<<"sorry player 2, you don't have any valid moves\n";
                        turn = true;
                        continue;
                    }
                    choice = player2.playerChoice(2);
                    while (true) {
                        if (player2.validCell(2, choice, board))
                            break;
                        choice = player1.playerChoice(2);
                    }
                    if (player2.game_over(board, 2)) {
                        cout << "CONGRATS PLAYER 2, YOU HAVE WON!!\n";
                        printBoard();
                        exit(0);
                    }
                }
                printBoard();
                turn = !turn;
            }
        }
        else if (game_choice=="2"){
            printBoard();
            while(true) {

                int choice;
                if (turn) {
                    if (!player1.ValidMove(board ,1)) {
                        cout<<"sorry player 1, you don't have any valid moves\n";
                        continue;
                    }
                    choice = player1.playerChoice(1);
                    while (true) {
                        if (player1.validCell(1, choice, board))
                            break;
                        choice = player1.playerChoice(1);
                    }
                }
                else {
                    cout<<"\n";
                    computer.bestMove(2, board);
                    cout<<"\n";
                }

                if (computer.game_finished(board)==1) {
                    cout << "COMPUTER HAS WON!!\n";
                    printBoard();
                    exit(0);
                }
                else if (computer.game_finished(board)==-1) {
                    cout << "CONGRATS PLAYER 1 , YOU HAVE WON!!\n";
                    printBoard();
                    exit(0);
                }
                printBoard();
                turn = !turn;
            }

        }
        else {
            cout<<"NOT VALID\n";
        }
    }

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

void print(char board[]);
void updateBoard(char board[], int index, char turn);
int getInput(char board[]);
bool isTaken(char board[], int index);
bool won(char board[], char turn);
int bestMove(char board[], char turn, int turnNum);
int calculateMove(char board[], char turn, int turnNum);

int main(){
    char board[9];
    char turn = 'X';
    int input;
    int turnNum = -1;
    char z = '1';
    
    for(int i = 0; i < 9; i++){
        board[i] = z;
        z++;
    }

    print(board);
    while (turnNum < 9 && !won(board, turn)){
        turnNum++;
        if (turn == 'X'){
            turn = 'O';
        } else {
            turn = 'X';
        }

        input = getInput(board);
        if (input == 10){
            input = bestMove(board, turn, turnNum);
        }
        updateBoard(board, input, turn);

        print(board);
    }
    if (turnNum < 9){
        cout << turn << " wins!" << endl;
    }

    return 0;
}

void print(char board[]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << board[(i*3) + j] << "  ";
        }
        cout << endl;
    }
}

void updateBoard(char board[], int index, char turn){
    board[index - 1] = turn;
}

int getInput(char board[]){
    int input;
    cout << "Please enter which number square you would like to place, or 10 to have the AI choose:" << endl;
    cin >> input;
    cout << endl;
    while (input < 1 || input > 10 || isTaken(board, input)){
        if (input < 1 || input > 10){
            cout << "Please input a number 1-10" << endl;
        } else{
            cout << "That square is chosen, please input a different number 1-10" << endl;
        }
        cin >> input;
        cout << endl;
    }
    return input;
}

bool isTaken(char board[], int index){
    if (board[index - 1] == 'X' || board[index - 1] == 'O'){
        return true;
    }
    return false;
}

bool won(char board[], char turn){
    bool win = false;
    if(board[0] == turn && board[4] == turn && board[8] == turn){
        win = true;
    } else if(board[2] == turn && board[4] == turn && board[6] == turn){
        win = true;
    } else if(board[0] == turn && board[3] == turn && board[6] == turn){
        win = true;
    } else if(board[1] == turn && board[4] == turn && board[7] == turn){
        win = true;
    } else if(board[2] == turn && board[5] == turn && board[8] == turn){
        win = true;
    } else if(board[0] == turn && board[1] == turn && board[2] == turn){
        win = true;
    } else if(board[3] == turn && board[4] == turn && board[5] == turn){
        win = true;
    } else if(board[6] == turn && board[7] == turn && board[8] == turn){
        win = true;
    } 

    return win;
}

int bestMove(char board[], char turn, int turnNum){
    int index = 0;
    int indexScore[9];
    char AIboard[9];
    int antiTurn;
    if (turn == 'X'){
        antiTurn = 'O';
    } else {
        antiTurn = 'X';
    }
    for(int i = 0; i < 9; i++){
        AIboard[i] = board[i];
        indexScore[i] = -99;
    }
    
    if(!isTaken(board, 1)){
        AIboard[0] = turn;
        if (won(AIboard, turn)){
            indexScore[0] = 100;
        } else {
            indexScore[0] = calculateMove(AIboard, antiTurn, turnNum);
        }
    }
    return index;
}

int calculateMove(char board[], char turn, int turnNum){
    int score;
    int antiTurn;
    if (turn == 'X'){
        antiTurn = 'O';
    } else {
        antiTurn = 'X';
    }

    for (int i = turnNum + 1; i < 9; i++){
        
    }

    return score;
}
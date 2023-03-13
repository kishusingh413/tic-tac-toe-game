#include <iostream>

using namespace std;

// Board size constants
const int ROWS = 3;
const int COLS = 3;

// Board representation
char board[ROWS][COLS] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

// Function to display the board
void displayBoard() {
    cout << "   1   2   3" << endl;
    cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to check if the game has ended in a win or a draw
char checkWin(char board[3][3]) {
    // Check rows for win
    for (int row = 0; row < ROWS; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            return board[row][0];
        }
    }

    // Check columns for win
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return board[0][col];
        }
    }

    // Check diagonals for win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check for draw
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == ' ') {
                return ' ';
            }
        }
    }

    return 'D';
}
bool checkempty(char board[3][3]){
    for(int i=0 ;i<3 ;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' ') return false ;
        }
    }

    return true ;
}

// Main function
int main() {
    // Initialize variables
    int row, col;
    char currentPlayer = 'X';

    // Display instructions
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1 is X and Player 2 is O." << endl;
    cout << "To make a move, enter the row and column number of the position you want to mark." << endl;

    // Loop until game ends
    while (checkempty) {
        // Display board and get player move
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> row >> col;

        // Check if move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Update
        board[row-1][col-1]=currentPlayer ;
        if(currentPlayer=='X') currentPlayer='O' ;
        else currentPlayer='X' ;

        if( checkWin(board)=='X' || checkWin(board)=='O'){
            break ;
        }
    }
    if(checkWin(board)=='D' || checkWin(board)==' '){
        cout<<"The game end with a draw"<<endl ;

    }else {
        cout<<"The winner is"<< checkWin(board)<<endl ;
    }

}

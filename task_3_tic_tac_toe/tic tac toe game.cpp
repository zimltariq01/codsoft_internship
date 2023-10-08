#include <iostream>
#include <string>

using namespace std;

const int BOARD_SIZE = 3;

// Function to display the Tic Tac Toe board
void displayBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    // Get player names
    string player1, player2;
    cout << "Enter name of player 1: ";
    cin >> player1;
    cout << "Enter name of player 2: ";
    cin >> player2;

    // Initialize board
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Game loop
    char currentPlayer = 'X';
    bool gameOver = false;
    while (!gameOver) {
        // Display board
        displayBoard(board);

        // Get player move
        int row, col;
        cout << currentPlayer << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;
        row--;
        col--;

        // Check if move is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '-') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make move
        board[row][col] = currentPlayer;

        // Check if game is over
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else {
            bool boardFull = true;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == '-') {
                        boardFull = false;
                        break;
                    }
                }
                if (!boardFull) {
                    break;
                }
            }
            if (boardFull) {
                displayBoard(board);
                cout << "Draw!" << endl;
                gameOver = true;
            } else {
                currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
            }
        }
    }

    return 0;
}

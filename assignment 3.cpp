#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& gameBoard) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << gameBoard[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool isGameOver(const vector<vector<char>>& gameBoard, char playerSymbol) {
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[i][0] == playerSymbol && gameBoard[i][1] == playerSymbol && gameBoard[i][2] == playerSymbol)
            return true;
        if (gameBoard[0][i] == playerSymbol && gameBoard[1][i] == playerSymbol && gameBoard[2][i] == playerSymbol)
            return true;
    }

    if ((gameBoard[0][0] == playerSymbol && gameBoard[1][1] == playerSymbol && gameBoard[2][2] == playerSymbol) ||
        (gameBoard[0][2] == playerSymbol && gameBoard[1][1] == playerSymbol && gameBoard[2][0] == playerSymbol))
        return true;

    return false;
}

int main() {
    vector<vector<char>> gameBoard(3, vector<char>(3, ' '));
    bool player1Turn = true;

    while (true) {
        displayBoard(gameBoard);

        char playerSymbol = player1Turn ? 'O' : 'X';
        cout << "Player " << (player1Turn ? 1 : 2) << "'s turn. Enter row and column (0-2): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || gameBoard[row][col] != ' ') {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        gameBoard[row][col] = playerSymbol;

        if (isGameOver(gameBoard, playerSymbol)) {
            displayBoard(gameBoard);
            cout << "Player " << (player1Turn ? 1 : 2) << " wins!" << endl;
            break;
        }

        bool tie = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (gameBoard[i][j] == ' ') {
                    tie = false;
                    break;
                }
            }
            if (!tie) break;
        }
        if (tie) {
            displayBoard(gameBoard);
            cout << "It's a tie!" << endl;
            break;
        }

        player1Turn = !player1Turn;
    }

    return 0;
}

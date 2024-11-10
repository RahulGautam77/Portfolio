#include <iostream>
#include <string>

using namespace std;

const char EMPTY = '.';
char board[8][8];

void initializeBoard() {
    const string initialSetup =
        "rnbqkbnr"
        "pppppppp"
        "........"
        "........"
        "........"
        "........"
        "PPPPPPPP"
        "RNBQKBNR";
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = initialSetup[i * 8 + j];
        }
    }
}

void printBoard() {
    cout << "  a b c d e f g h\n";
    cout << " +----------------\n";
    for (int i = 0; i < 8; i++) {
        cout << (8 - i) << "|";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) {
    // Basic validation: check if the move is within bounds and the starting square is not empty
    if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
        toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8) {
        return false;
    }
    if (board[fromRow][fromCol] == EMPTY) {
        return false;
    }
    return true; // You can expand this to include piece-specific movement rules
}

void movePiece(const string& from, const string& to) {
    int fromRow = 8 - (from[1] - '0');
    int fromCol = from[0] - 'a';
    int toRow = 8 - (to[1] - '0');
    int toCol = to[0] - 'a';

    if (isValidMove(fromRow, fromCol, toRow, toCol)) {
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = EMPTY;
    } else {
        cout << "Invalid move. Try again." << endl;
    }
}

int main() {
    initializeBoard();
    string input;

    while (true) {
        printBoard();
        cout << "Enter your move (e.g., e2 e4) or 'exit' to quit: ";
        cin >> input;

        if (input == "exit") {
            break;
        }

        string from = input;
        string to;
        cin >> to;

        movePiece(from, to);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

#define EMPTY '.'

char board[8][8];

void initializeBoard() {
    const char *initialSetup = 
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
    printf("  a b c d e f g h\n");
    printf(" +----------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int fromRow, int fromCol, int toRow, int toCol) {
    // Basic validation: check if the move is within bounds and the starting square is not empty
    if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
        toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8) {
        return 0; // Invalid move
    }
    if (board[fromRow][fromCol] == EMPTY) {
        return 0; // Invalid move
    }
    return 1; // Valid move
}

void movePiece(const char *from, const char *to) {
    int fromRow = 8 - (from[1] - '0');
    int fromCol = from[0] - 'a';
    int toRow = 8 - (to[1] - '0');
    int toCol = to[0] - 'a';

    if (isValidMove(fromRow, fromCol, toRow, toCol)) {
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = EMPTY;
    } else {
        printf("Invalid move. Try again.\n");
    }
}

int main() {
    initializeBoard();
    char input[10];

    while (1) {
        printBoard();
        printf("Enter your move (e.g., e2 e4) or 'exit' to quit: ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        char from[3], to[3];
        sscanf(input, "%s %s", from, to);
        movePiece(from, to);
    }

    return 0;
}
import java.util.Scanner;

class Chess {
    private static final char EMPTY = '.';
    private static char[][] board = new char[8][8];

    public static void main(String[] args) {
        initializeBoard();
        Scanner scanner = new Scanner(System.in);
        String input;

        while (true) {
            printBoard();
            System.out.println("Enter your move (e.g., e2 e4) or 'exit' to quit:");
            input = scanner.nextLine();

            if (input.equalsIgnoreCase("exit")) {
                break;
            }
            movePiece(input);
        }

        scanner.close();
    }

    private static void initializeBoard() {
        String initialSetup = 
            "rnbqkbnr" +
            "pppppppp" +
            "........" +
            "........" +
            "........" +
            "........" +
            "PPPPPPPP" +
            "RNBQKBNR";
        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = initialSetup.charAt(i * 8 + j);
            }
        }
    }

    private static void printBoard() {
        System.out.println("  a b c d e f g h");
        System.out.println(" +----------------");
        for (int i = 0; i < 8; i++) {
            System.out.print((8 - i) + "|");
            for (int j = 0; j < 8; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static void movePiece(String input) {
        String[] parts = input.split(" ");
        if (parts.length != 2) {
            System.out.println("Invalid input. Please enter a valid move.");
            return;
        }

        String from = parts[0];
        String to = parts[1];

        int fromRow = 8 - Character.getNumericValue(from.charAt(1));
        int fromCol = from.charAt(0) - 'a';
        int toRow = 8 - Character.getNumericValue(to.charAt(1));
        int toCol = to.charAt(0) - 'a';

        if (isValidMove(fromRow, fromCol, toRow, toCol)) {
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = EMPTY;
        } else {
            System.out.println("Invalid move. Try again.");
        }
    }

    private static boolean isValidMove(int fromRow, int fromCol, int toRow, int toCol) {
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
}
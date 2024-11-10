class Chess:
    def __init__(self):
        self.board = [
            ["r", "n", "b", "q", "k", "b", "n", "r"],
            ["p", "p", "p", "p", "p", "p", "p", "p"],
            [".", ".", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", ".", "."],
            [".", ".", ".", ".", ".", ".", ".", "."],
            ["P", "P", "P", "P", "P", "P", "P", "P"],
            ["R", "N", "B", "Q", "K", "B", "N", "R"],
        ]

    def print_board(self):
        print("  a b c d e f g h")
        print(" +----------------")
        for i in range(8):
            print(8 - i, "|", end="")
            for j in range(8):
                print(self.board[i][j], end=" ")
            print()

    def is_valid_move(self, from_row, from_col, to_row, to_col):
        if (0 <= from_row < 8 and 0 <= from_col < 8 and
                0 <= to_row < 8 and 0 <= to_col < 8):
            if self.board[from_row][from_col] != ".":
                return True
        return False

    def move_piece(self, from_pos, to_pos):
        from_row = 8 - int(from_pos[1])
        from_col = ord(from_pos[0]) - ord('a')
        to_row = 8 - int(to_pos[1])
        to_col = ord(to_pos[0]) - ord('a')

        if self.is_valid_move(from_row, from_col, to_row, to_col):
            self.board[to_row][to_col] = self.board[from_row][from_col]
            self.board[from_row][from_col] = "."
        else:
            print("Invalid move. Try again.")

    def play(self):
        while True:
            self.print_board()
            move = input("Enter your move (e.g., e2 e4) or 'exit' to quit: ")
            if move.lower() == "exit":
                break
            try:
                from_pos, to_pos = move.split()
                self.move_piece(from_pos, to_pos)
            except ValueError:
                print("Invalid input. Please enter a valid move.")

if __name__ == "__main__":
    game = Chess()
    game.play()
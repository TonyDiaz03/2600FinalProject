#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3
#define SYMBOLS 2

const char symbols[SYMBOLS] = {'X', 'O'};

void printBoard(char board[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c ", board[row][col]);
            if (col < COLS - 1) {
                printf("| ");
            }
        }
        printf("\n");
        if (row < ROWS - 1) {
            printf("---------\n");
        }
    }
}

bool makeMove(char board[ROWS][COLS], int row, int col, int player) {
    if (board[row][col] != ' ') {
        // Cell is already occupied
        return false;
    }
    board[row][col] = symbols[player];
    return true;
}

int checkWin(char board[ROWS][COLS]) {
    // Check rows
    for (int row = 0; row < ROWS; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
            return board[row][0];
        }
    }

    // Check columns
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            return board[0][col];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // Check for draw
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == ' ') {
                // Game is not over yet
                return 0;
            }
        }
    }

    // Game is a draw
    return -1;
}

int main() {
    char board[ROWS][COLS];

    // Initialize board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }

    int player = 0;
    int result;
    while (true) {
        printBoard(board);

	         // Get player's move
        int row, col;
        printf("Player %c's turn. Enter row and column: ", symbols[player]);
        scanf("%d %d", &row, &col);

        // Make move
        if (!makeMove(board, row, col, player)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Check if game is over
        result = checkWin(board);
        if (result != 0) {
            break;
        }

        // Switch players
        player = (player + 1) % SYMBOLS;
    }

    // Print result
    printBoard(board);
    if (result == -1) {
        printf("It's a draw!\n");
    } else {
        printf("Player %c wins!\n", result);
    }

    return 0;
}



#include <stdio.h>
#include <stdbool.h>

void print_board(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("%c|%c|%c\n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("-----\n");
        }
    }
}

int take_move_row(char player) {
    int row;
    printf("enter row (1-3) for player %c: ", player);
    scanf("%d", &row);
    row--;
    return row;
}

int take_move_col(char player) {
    int col;
    printf("enter column (1-3) for player %c: ", player);
    scanf("%d", &col);
    col--;
    return col;
}

bool is_valid_move(char board[3][3], int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

bool check_for_win(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}

int main() {
    
    char board[3][3] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' }
    };

    int row, col;
    int moves = 0;
    char player = 'X';

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player X goes first.\n");

    while (true) {
        print_board(board);
        row = take_move_row(player);
        col = take_move_col(player);
        while (is_valid_move(board, row, col) == false) {
            printf("Invalid move. Try again.\n");
            row = take_move_row(player);
            col = take_move_col(player);
        }
        board[row][col] = player;
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
        moves++;
        if (check_for_win(board)) {
            print_board(board);
            printf("Player %c wins!\n", player == 'X' ? 'O' : 'X');
            break;
        } else if (moves == 8) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        } else {
            continue;
        }
    }
    
    return 0;
}

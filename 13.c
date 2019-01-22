#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef enum {white, black} color;

typedef struct {
    color c;
    int i;
    int j;
} Piece;

void print_board(Piece* board[][BOARD_SIZE]) {
    int i, j;
    for (i=0; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            printf("%c\t", board[i][j] ? (board[i][j]->c == black ? 'b' : 'w' ): '-');
        }
        putchar('\n');
    }
}

int is_even(int n) {
    return !(n%2);
}

void start_board(Piece* board[][BOARD_SIZE]) {
    int i,j;
    /* initialize black pieces */
    for (i=0; i<3; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if (is_even(i+j)) {
                board[i][j] = NULL;
            } else {
                board[i][j] = (Piece*) malloc(sizeof(Piece));
                if (!board[i][j]) {
                    exit(1);
                }
                board[i][j]->c = black;
                board[i][j]->i = i;
                board[i][j]->j = j;
            }
        }
    }

    /* initialize empty lines */
    for (i=3; i<5; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = NULL;
        }
    }

    /* initialize white pieces */
    for (i=5; i<BOARD_SIZE; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if (is_even(i+j)) {
                board[i][j] = NULL;
            } else {
                board[i][j] = (Piece*) malloc(sizeof(Piece));
                if (!board[i][j]) {
                    exit(1);
                }
                board[i][j]->c = white;
                board[i][j]->i = i;
                board[i][j]->j = j;
            }
        }
    }
}

int in_board(int i, int j) {
    return i>=0 && j>=0 && i<BOARD_SIZE && j<BOARD_SIZE;
}

int valid_move(Piece* piece, int to_i, int to_j) {
    if (!in_board(piece->i, piece->j)) {
        return 0;
    }
    if (to_j+1 != piece->j && to_j-1 != piece->j) {
        return 0;
    }
    if (piece->c == white &&
        (piece->i != to_i+1)) {
        return 0;
    }
    if (piece->c == black &&
            (piece->i != to_i-1)) {
        return 0;
    }
    return 1;
}

int move_piece(Piece* board[][BOARD_SIZE], Piece* piece, int to_i, int to_j) {
    //     index out of board        not empty         not valid in compared to piece
    if (!in_board(to_i, to_j) || board[to_i][to_j] || !valid_move(piece, to_i, to_j)) {
        return 0;
    }
    board[piece->i][piece->j] = NULL;
    board[to_i][to_j] = piece;
    return 1;
}


int main() {
    Piece* board[BOARD_SIZE][BOARD_SIZE];
    start_board(board);
    print_board(board);
}

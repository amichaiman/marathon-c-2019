#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {white, black} color;


typedef struct {
    int i;
    int j;
    color c;
} Peice;

int in_board(int i, int j) {
    return i>=0 && j>=0 && j<BOARD_SIZE && i<BOARD_SIZE;
}

int valid_move(Peice* p, int to_i, int to_j) {
    if (p->c == white && p->i-to_i == 1 && abs(p->j-to_j) == 1) {
        return 1;
    }
    if (p->c == black && to_i-p->i == 1 && abs(to_j-p->j) == 1) {
        return 1;
    }
    return 0;

}

int move_piece(Peice* board[][BOARD_SIZE], Peice* to_move, int to_i, int to_j) {
    if (!in_board(to_i, to_j) || board[to_i][to_j] || !valid_move(to_move, to_i, to_j)) {
        return 0;
    }
    return 1;
}

void print_board(Peice* board[][BOARD_SIZE]) {
    int i,j;

    for (i=0; i<BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c\t", board[i][j] == NULL ? '-' : (board[i][j]->c == black ? 'b' : 'w'));
        }
        putchar('\n');
    }
}

void start_board(Peice* board[][BOARD_SIZE]) {
    int i,j;

    for (i=0; i<3; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if ((i+j)%2 == 0){
                board[i][j] = NULL;
            } else {
                board[i][j] = (Peice*) malloc (sizeof(Peice));
                board[i][j]->c = black;
            }
        }
    }

    for (i=3; i<5; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = NULL;
        }
    }

    for (i=5; i<8; i++) {
        for (j=0; j<BOARD_SIZE; j++) {
            if ((i+j)%2 == 0){
                board[i][j] = NULL;
            } else {
                board[i][j] = (Peice*) malloc (sizeof(Peice));
                board[i][j]->c = white;
            }
        }
    }
    print_board(board);
}

int main() {
    Peice* board[BOARD_SIZE][BOARD_SIZE];
    start_board(board);
    return 0;
}



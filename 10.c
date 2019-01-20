#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 5

#define MAX_RAND 10

int in_matrix(int rows, int cols, int i, int j) {
    return i>=0 && j>=0 && i<rows && j<cols;
}

int is_horse_square(int matrix[][M], int rows, int cols, int row_index, int col_index) {
    int offset_i[] = {1,2,2,1,-1,-2,-2,1};
    int offset_j[] = {-2,-1,1,2,-2,-1,1,2};
    int number_of_potential_spots = 8, i;

    if (!in_matrix(rows, cols, row_index, col_index)) {
        return -1;
    }

    for (i=0; i<number_of_potential_spots; i++) {
        if (in_matrix(rows, cols, row_index+offset_i[i], col_index+offset_j[i])
            && matrix[row_index+offset_i[i]][col_index+offset_j[i]] != matrix[row_index][col_index]) {
            return 0;
        }
    }
    return 1;
}

int is_horse_matrix(int matrix[][M], int rows, int cols) {
    int i,j;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            if (is_horse_square(matrix, rows, cols, i, j)) {
                return 1;
            }
        }
    }
    return 0;
}

void fill_random_matrix(int matrix[][M], int rows, int cols) {
    int i,j;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            matrix[i][j] = rand()%MAX_RAND;
        }
    }

}
int main() {
    int matrix[N][M] = {{5,2,1,-1,5},
                        {7,-3,5,4,0},
                        {5,1,0,0,5},
                        {3,5,5,5,7},
                        {1,3,2,4,5}};

    int random_matrix[N][M];

    srand(time(NULL));

    fill_random_matrix(random_matrix,N,M);

    printf("it is%s a horse matrix\n", is_horse_matrix(random_matrix, N, M) ? "" : "n't");

    return 0;
}



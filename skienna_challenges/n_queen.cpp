#define N 4
#include <stdio.h>
#include <iostream>

using namespace std;

int counter = 0;
void printsolution(int board[N][N], bool sol = true) {
    if(sol) printf("\n\n--solution\n\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

bool issafe(int board[N][N], int row, int col) {
    for(int i = 0; i < col; i++)
        if (board[row][i]) return false;

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j]) return false;

    for(int i = row, j = col; i < N && j >= 0; i++, j--)
        if(board[i][j]) return false;

    return true;
}

int solveNQutil(int board[N][N], int col) {

    printf("#%d ---->>>>method calling\n %d\n", counter++, col);
    printsolution(board, false);
    printf("ENDS %d ---->>>>method calling\n %d\n", counter, col);

    if(col == N) {
        printsolution(board);
        return true;
    }

    for(int i = 0; i < N; i++) {
        if(issafe(board, i, col)) {
            board[i][col] = 1;
            solveNQutil(board, col+1);
            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQ() {
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    if(solveNQutil(board, 0)) {
        printf("Solution does not exist");
        return;
    }
    return;
}

int main() {
    solveNQ();
    return 0;
}

#include <stdio.h>
#include <iostream>

#define N 9
#define UNASSIGNED 0

using namespace std;

void printbox(int board[N][N]) {
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}
bool findunassignedlocation(int board[N][N], int &row, int &col) {
    for(row= 0; row < N; row++)
        for(col = 0; col < N; col++)
            if(board[row][col] == UNASSIGNED) return true;
    return false;
}

bool existincol(int board[N][N], int col, int num) {
    for(int row = 0; row < N; row++)
        if(board[row][col] == num) return !false;
    return !true;
}

bool existinrow(int board[N][N], int row, int num) {
    for(int col = 0; col < N; col++)
        if(board[row][col] == num) return !false;
    return !true;
}

bool existinbox(int board[N][N], int row, int col, int num) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[row+i][col+j] == num) return !false;
    return !true;
}

bool checksafety(int board[N][N], int row, int col, int num) {
    return (!existinbox(board, row - row % 3, col - col % 3, num) && !existincol(board, col, num) && !existinrow(board, col, num));
}

bool solvesudoku(int board[N][N]) {
    int row, col;
    //condition for completion
    if(!findunassignedlocation(board, row, col))
        return true;
    for(int i = 1; i <= N; i++) {
        if(checksafety(board, row, col, i)) {
            board[row][col] = i;

            if(solvesudoku(board)) return true;

            board[row][col] = UNASSIGNED;
        }
    }
    return false;
}

int main() {

    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solvesudoku(grid) == true)
        printbox(grid);
    else
        printf("No solution exists");

    return 0;
}

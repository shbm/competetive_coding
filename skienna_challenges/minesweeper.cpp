/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 10189 - Minesweeper
 * Technique: 2D Array / Matrix Boundary checking using
 *            co-ordinate array and for loop.
 */

#include<stdio.h>
#include<string.h>

#define MAXSIZE 101

static char MineField[MAXSIZE][MAXSIZE];

static const int drow[] = {0, 1, 1, 1, 0, -1, -1, -1};
static const int dcol[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main(){
    int n, m;

    int FieldNumber = 0;

    while( scanf("%d%d", &n, &m) ){

        getchar();

        for(int i = 0; i < n; ++i)
            scanf("%s", &MineField[i]);

        if(FieldNumber)
            printf("\n");

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){

                int temp = 0;

                // If mine found do nothing.
                if(MineField[i][j] == '*')
                    continue;

                // For each adjacent squares of the current square calculate mine count.
                // and set the count in current square.
                for(int k = 0; k < 8; ++k){

                    // Check if out of bound of the 2D array or matrix.
                    bool outofbound = (i + drow[k] < 0 || j + dcol[k] < 0 || i + drow[k] >= n || j + dcol[k] >= m );
                    printf("%d %d %c %d\n", i, j, MineField[i][j], outofbound);
                    if(outofbound) continue;

                    // Check the appropriate co-ordinate for mine, if mine found increase count.
                    if( MineField[i + drow[k] ][j + dcol[k]] == '*' )
                        ++temp;
                }

                // All adjacent squares checked set the mine count for current squares.
                MineField[i][j] = temp + '0';
            }
        }

        printf("Field #%d:\n", ++FieldNumber);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                putchar(MineField[i][j]);
            printf("\n");
        }
    }
    return 0;
}

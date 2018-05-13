#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <unordered_map>
#include <time.h>
#include <climits>

using namespace std;

#define M 10
#define N 10

// row and colomn index for traversing the 8 directions
int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// check if a cell is valid or not
// processed?
// is 0?
bool isvalid(int matrix[M][N], bool processed[M][N], int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N && processed[x][y] == false && matrix[x][y] != 0);
}

// floodfill like bfs
int count_island(int matrix[M][N], bool processed[M][N], int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    processed[x][y] = true;
    while(!q.empty()) {
        // always remember to initialize the
        // cordinates
        pair<int, int> node = q.front();
        x = node.first; // DON'T FORGET
        y = node.second; // DON'T FORGET
        q.pop();
        // process all the 8 adjaccent cells;
        for(int i = 0; i < 8; i++) {
            if(isvalid(matrix, processed, x+row[i], y+col[i])) {
                q.push(make_pair(x+row[i], y+col[i]));
                processed[x+row[i]][y+col[i]] = true;
            }
        }
    }
    return 1;
}


int main() {
    clock_t tStart = clock();

    int mat[M][N]=
    {
        { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
    };

    bool processed[M][N];

    int island = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(mat[i][j] != 0 && processed[i][j] == false) {
                island += count_island(mat, processed, i, j);
            }
        }
    }


    cout << island;
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

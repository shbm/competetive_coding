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

#define ROW 10
#define COL 10

int row[] = {-1, -1, 0, +1, +1, +1, 0, -1};
int col[] = {0, +1, +1, +1, 0, -1, -1, -1};

bool is_safe(int M[ROW][COL], int x, int y, int visited[ROW][COL]) {
    if(x >= 0 && x < ROW && y >= 0 && y < COL && visited[x][y] == 0 && M[x][y] == 1) {
        return 1;
    } else
        return 0;
}

void number_of_islands(int M[][COL], int x, int y, int visited[ROW][COL]) {

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    int count_of_island_unit=1;
    while(!q.empty()) {
        pair<int, int> point = q.front();
        q.pop();
        for(int i = 0; i < 8; i++) {
            if(is_safe(M, point.first+row[i], point.second+col[i], visited)) {
                visited[point.first+row[i]][point.second+col[i]] = 1;
                q.push(make_pair(point.first+row[i], point.second+col[i]));
                count_of_island_unit++;
            }
        }
    }
    cout << "ISLAND COUNT: " << count_of_island_unit << "\n";
}

int main() {

    clock_t tStart = clock();
    int M[ROW][COL] = {
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


    int island = 0;
    int visited[ROW][COL] = {0};
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(visited[i][j] == 0 && M[i][j] == 1) {
                number_of_islands(M, i, j, visited);
                island++;
            }
        }
    }
    cout << island;

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

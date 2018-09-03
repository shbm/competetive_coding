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

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int o = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);
    if(o == 0) return 0;
    return (o > 0) ? 1: 2;
}

vector<Point> jarvis_scan(vector<Point> points) {
    int n = points.size();
    if(n<3) return {};

    vector<Point> hull;

    int l = 0;
    for(int i = 1; i < n; i++) {
        if(points[i].x < points[l].x)
            l = i;
    }

    int p = l, q;
    do {
        hull.push_back(points[p]);
        cout << "pushing";

        q = (p+1)%n;

        cout << "p: " << p << "     (p+1)%n: " << q <<"\n";
        for(int i = 0; i < n; i++) {
            if(orientation(points[p], points[i], points[q]) == 2) {
                cout << i << "--\n";
                q = i;
            }
        }

        p = q;
    } while(p != l);
    cout << "HULL_SIZE:" << hull.size() << "\n";
    return hull;
}

int main() {
    clock_t tStart = clock();

    vector<Point> points {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};;
    vector<Point> p = jarvis_scan(points);
    cout << p.size();
    for(auto &i: p) {
        cout << "---" << i.x << " " << i.y << "\n";
    }

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

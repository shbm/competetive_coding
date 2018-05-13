#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;
    while(N--) {
        vector<int> streets;
        int r;
        cin >> r;
        while(r--) {
            int T;
            cin >> T;
            streets.push_back(T);
        }
        sort(streets.begin(), streets.end());
        int median = streets[streets.size()/2];
        int distance = 0;
        for(int i = 0; i < streets.size(); i++) {
            distance += abs(median - streets[i]);
        }
        cout << distance << "\n";
    }
    return 0;
}

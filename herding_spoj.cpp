#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <map>
#include <queue>

using namespace std;

map<int, pair<int, int> > done;
char matrix[1000][1000];

pair<int, int> direction(char s) {
    if(s == 'E') {
        return pair<int, int> (0, 1);
    } else if (s == 'W') {
        return pair<int, int> (0, -1);
    } else if(s == 'N') {
        return pair<int, int> (-1, 0);
    }else {
        return pair<int, int> (1, 0);
    }
}
int generate_rank(int i, int j, int r, int c) {
	return i*c+j;
}
void BFS(int r, int c, int source) {
	queue< pair<int, pair<int, int> > > q;
	q.push(make_pair(source, make_pair(done[source].first, done[source].second)));
	while(!q.empty()) {
		source = (q.front()).first;
		q.pop();
		int i = done[source].first, j = done[source].second;
		pair<int, int> d = direction(matrix[i][j]);
		int r = generate_rank(i+d.first, j+d.second, r, c);
		done.erase(source);
		q.push(make_pair(r , make_pair(done[r].first, done[r].second)));
		cout << source;
	}
}

int main() {

    int r = 3, c = 4;
    // cin >> r >> c;
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            done[i] = make_pair(i, j);
        }
    }
    string s = "SWWWSEWNEEEN";
    int k = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            matrix[i][j] = s[j+i*c];
            done[k++] = make_pair(i, j);
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << matrix[i][j];
        }
        cout << "\n";
    }
    k = 1;
    for(map<int, pair<int, int> > :: iterator i = done.begin(); i != done.end(); i++) {
    	cout << i->first << " (" << i->second.first << "," << i->second.second << ")\t\t";
    	if(k++ % c == 0) cout << "\n";
    }
    int connected_componenets = 0;
    while(!done.empty()) {
    	if(connected_componenets == 5) break;
    	connected_componenets++;
    	map<int, pair<int, int> > :: iterator i = done.begin();
    	BFS(r, c, i->first);
    }
    cout << "\nconnected_componenets " << connected_componenets;
}
#include <iostream>
#include <string.h>
#include <set>

using namespace std;

int main() {
    clock_t tStart = clock();

    string str = "appleap";
    cin >> str;
    set<char> st(str.begin(), str.end());
    string maximum;
    int f = true;
    for(char i: st) {
        string s = "";
        for(char j: str) {
            if(j == i)
                continue;
            s = s+j;
        }
        if(f == true) {
            maximum = s;
            f = false;
        } else {
            int z=strcmp(s.c_str(), maximum.c_str());
            if(z < 0) {
                maximum = s;
            }
        }
    }
    cout << maximum;

    return 0;
}

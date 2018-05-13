#include <iostream>
#include<cmath>

using namespace std;

int main() {
    int x[] = {5, 1, 4, 2, -1, 6};
    int l = sizeof(x)/sizeof(x[0]);
    int dif[l-1] = {0};
    dif[0] = 1;
    for(int i = 0; i<l-1; i++) {
        int d = abs(x[i+1] - x[i]);
        if(d >= 0 && d <= (l-1)) {
            dif[d] = 1;
        }
    }
    bool jj = true;
    for(int i = 0; i<l-1; i++) {
        if(dif[i] == 0) {
            jj = false;
        }
    }
    jj ? printf("%s", "Jolly Jumper") : printf("%s", "Not Jolly Jumper");
    return 0;
}

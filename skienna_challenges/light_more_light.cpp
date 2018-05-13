#include <iostream>

using namespace std;

int main() {

    int bulb[10000] = {-1};
    for(int i = 0; i < sizeof(bulb)/sizeof(bulb[0]); i++) {
        for(int j = i; j < sizeof(bulb)/sizeof(bulb[0]); j = j+i) {
            bulb[j] *= -1;
        }
    }
    cout << bulb[6241];
    return 0;
}

#include <iostream>

using namespace std;

int a[100000];

int set_bits(int n) {
    int cont = false;
    while(n) {
        int s = (n & 1);
        if(cont == true && s == 1) {
            return true;
        }
        if(s == 1) {
            cont = true;
        } else {
            cont = false;
        }
        n = n >> 1;
    }
    return false;
}

int main() {

    int n;
    int q;
    cin >> n;
    cin >> q;
    int number;
    for(int i = 0; i < n; i++) {
        cin >> number;
        a[i] = set_bits(number);

    }
    int l, r;
    while(q--) {
        int count = 0;
        cin >> l;
        cin >> r;
        for(int i = l-1; i < r; i++) {
            if(a[i] == true)
                count++;
        }
        cout << count << "\n";
    }
    return 0;
}

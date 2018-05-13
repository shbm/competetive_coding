#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int find_kth(int *, int, int);

int main() {

    int a[] = {1,2,3,4,5,1000,8,9,99};
    int n = sizeof(a)/sizeof(int);
    int k = n/2;
    cout << "\nk := " << k << "\t|\tmedian_of_meadin: " << find_kth(a, n, k);
    k = n-1;
    cout << "\nk := " << k << "\t|\tmedian_of_meadin: " << find_kth(a, n, k);
    k = 0;
    cout << "\nk := " << k << "\t|\tmedian_of_meadin: " << find_kth(a, n, k);
    return 0;
}

int find_kth(int *v, int n, int k) {
    if (n == 1 && k == 0) return v[0];

    int m = (n + 4)/5;
    int *medians = new int[m];
    for (int i=0; i<m; i++) {
        if (5*i + 4 < n) {
            int *w = v + 5*i;
            for (int j0=0; j0<3; j0++) {
                int jmin = j0;
                for (int j=j0+1; j<5; j++) {
                    if (w[j] < w[jmin]) jmin = j;
                }
                swap(w[j0], w[jmin]);
            }
            medians[i] = w[2];
        } else {
            medians[i] = v[5*i];
        }
    }

    int pivot = find_kth(medians, m, m/2);
    delete [] medians;

    for (int i=0; i<n; i++) {
        if (v[i] == pivot) {
            swap(v[i], v[n-1]);
            break;
        }
    }

    int store = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i] < pivot) {
            swap(v[i], v[store++]);
        }
    }
    swap(v[store], v[n-1]);

    if (store == k) {
        return pivot;
    } else if (store > k) {
        return find_kth(v, store, k);
    } else {
        return find_kth(v+store+1, n-store-1, k-store-1);
    }
}

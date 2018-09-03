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

class BIT {
    private:
        vector<int> bit_array;
    public:
        BIT(vector<int> array) {
            bit_array = vector<int>(array.size()+1, 0);

            for(int i = 0; i < array.size(); i++) {
                bit_array[i+1] = array[i];
            }

            // populating the BIT
            for(int i = 1; i < bit_array.size(); i++) {
                // get the next index
                int index = i + (i & -i);
                // if the index does not go away from the size of the vector bit_array
                if(index < bit_array.size()) {
                    // update each value of the bit_array
                    bit_array[index] = bit_array[index] + bit_array[i];
                }
            }
        }

        int prefix_query(int idx) {
            int result = 0;
            idx++;
            while(idx > 0) {
                result = result + bit_array[idx];
                // get the parent index
                idx = idx - (idx & -idx);
            }
            return result;
        }

        void update(int idx, int value) {
            idx++;
            while(idx < bit_array.size()) {
                bit_array[idx] += value;
                idx = idx + (idx & -idx);
            }
        }

        void print_bit() {
            int l = 0;
            for(auto i: bit_array) {
                cout << ++l << " -> " << i << "\n";
            }
        }

        int range_sum(int idx1, int idx2) {
            return prefix_query(idx2) - prefix_query(idx1 - 1);
        }
};

int main() {
    clock_t tStart = clock();

    vector<int> a{1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5};

    int s=0;
    for(auto i: a) {
        s += i;
    }
    cout << "\n" << s << "\n";

    BIT bit(a);
    bit.print_bit();
    cout << bit.prefix_query(a.size()-1);

    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

static map<int, int> cache;
map<int, int>::iterator it;
int fib(int num) {
    if(num == 0 || num == 1)
        return cache[num];
    it = cache.find(num);
    if(it == cache.end()) {
        cache[num] = fib(num-1) + fib(num-2);
        return cache[num];
    } else {
        return cache[num];
    }
}
int main() {
    cache[0] = 0;
    cache[1] = 1;
    printf("%d\n", fib(20));
    return 0;
}

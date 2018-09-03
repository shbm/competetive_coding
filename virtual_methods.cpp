#include <stdio.h>
#include <queue>
#include <sstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <time.h>
#include <bitset>
#include <climits>

using namespace std;
class Person {
    public:
        Person() {
            cout << "Person Constructor\n";
        }
        virtual void abt() {
            cout << "I'm Person\n";
        }
        ~Person() {
            cout << "Person Dead\n---\n\n";
        }
};

class Student: public Person {
    public:
        Student() {
            cout << "Student Costructor\n";
        }

        void abt() {
            cout << "I'm a Student\n";
        }
        ~Student() {
            cout << "Student dead!\n---\n\n";
        }
};

int main() {
    clock_t tStart = clock();


    Person *q = new Student();
    q->abt();
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

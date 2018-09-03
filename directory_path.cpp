#include <stdio.h>
#include <queue>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <time.h>
#include <climits>
#include <string>
#include <stack>
#include <sstream>
#include <iostream>


using namespace std;

string simplifyPath(string A) {
    istringstream s(A);
    string str;

    stack<string> stk;
    while(getline(s, str, '/')) {
        if(str == ".") continue;
        else if(str == ".." && !stk.empty()) stk.pop();
        else stk.push(str);
    }

    string sol = "";
    while(!stk.empty()) {
        sol += "/" + stk.top();
        stk.pop();
    }

    return sol.substr(0, sol.length() - 1);
}

int main() {
    clock_t tStart = clock();

    string path = "/./../../giq/xns/zvk/../vkd/qhp/pyf/wie/atv/thv/./kqs/seq/fzw/cav/./../.././rjn/elx/gyn/lla/gkd/zig/qud/vyx/./eqd/ple/vst/loc/./../uak/wvz/vxe/ibc/../bns/psb/./kjo/bky/oks/./cjg/yyh/spf/abt";


    cout << simplifyPath(path);
    printf("\nTime taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

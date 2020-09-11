#include <bits/stdc++.h>
using namespace std;

class Solution {    // oj有问题
public:
    bool judgeCircle(string moves) {
        int row = 0;
        int col = 0;
        for(auto x : moves){
            if(x == 'U') ++col;
            else if(x == 'D') --col;
            else if(x == 'L') --row;
            else ++row;
        }
        return !col && !row;
    }
};
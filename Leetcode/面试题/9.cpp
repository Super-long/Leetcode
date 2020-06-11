// 回文数
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int lhs = 0, rhs = str.size();
        while(rhs > lhs){
            if(str[lhs]!=str[rhs]){
                return false;
            }else {
                lhs++;
                rhs--;
            }
        }
        return true;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n/2; i++){ // 不可能等于0
            if(n % i == 0){
                bool match = true;
                for(int j = i; j < n; ++j){
                    if(s[j] != s[j-i]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    return true;
                }
            }
        }
        return false;
    }
};

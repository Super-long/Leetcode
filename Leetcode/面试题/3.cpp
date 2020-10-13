#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<char> vis;
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int lhs = 0;
        int rhs = 0;
        int res = -1;
        while(rhs < s.size()){
            if(vis.find(s[rhs]) != vis.end()){
                vis.erase(s[lhs]);
                ++lhs;
            } else {
                vis.insert(s[rhs]);
                ++rhs;
                res = max(res, rhs - lhs);
            }
        }
        return res;
    }
};
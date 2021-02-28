#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int lhs = 0;
        unordered_map<char, int> vis;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            vis[s[i]]++;
            while(vis[s[i]] > 1){
                vis[s[lhs]]--;
                if(s[lhs++] == s[i]){
                    break;
                }
            }
            res = max<int>(res, i - lhs + 1);
        }
        return res;
    }
};
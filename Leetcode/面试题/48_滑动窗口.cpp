#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int lhs = 0, rhs = 0;
        int res = 0;
        while(rhs < s.size()){
            if(mp.find(s[rhs]) != mp.end()){
                lhs = max(lhs , mp[s[rhs]]+1);
            }
            mp[s[rhs]] = rhs; //更新mp中是[rhs]的下一个索引
            rhs++;
            res = max(res, rhs-lhs);
        }
        return res;
    }
};


int main(){
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution_temp {
public:
    int lengthOfLongestSubstring(string s) {
        int lhs = 0;
        int rhs = 0;
        unordered_set<char> mp;
        int res = 0;
        while (rhs < s.size()){
            if(mp.find(s[rhs]) == mp.end()){
                res = max(res, rhs - lhs + 1);
                mp.insert(s[rhs]);
                rhs++;
            } else { // 新插入的字符不在答案中
                mp.erase(s[lhs++]);

            }
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> vis;
        int lhs = 0;
        int rhs = 0;
        int res = 0;
        while(rhs < s.size()){
            if(vis.find(s[rhs]) == vis.end()){
                vis.insert(s[rhs]);
                res = max(res, rhs - lhs + 1);
                rhs++;
            } else {
                vis.erase(s[lhs]);
                lhs++;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.lengthOfLongestSubstring("") << endl;
    return 0;
}

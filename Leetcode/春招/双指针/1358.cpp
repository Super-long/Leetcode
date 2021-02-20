#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {  // 这题可以用二分解
        int lhs = 0;
        unordered_map<char, int> vis;
        int res = 0;
        for (size_t i = 0; i < s.size(); i++){
            vis[s[i]]++;
            if(vis.size() == 3){
                while(lhs <= i && vis.size() == 3){
                    res += s.size() - i;
                    vis[s[lhs]]--;
                    if(vis[s[lhs]] == 0) vis.erase(s[lhs]);
                    lhs++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    std::cout << sol.numberOfSubstrings("abc") << endl;
    return 0;
    }
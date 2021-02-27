#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        const int len = s.size();
        vector<bool> flag(26, 0);
        auto check = [&](const vector<int>& vec) -> bool {
            for(int i = 0; i < vec.size(); i++) {
                if(vec[i] > 0 && vec[i] < k){
                    return false;
                }
            }
            return true;
        };
        int result = 0;
        for (int i = 0; i < len - k + 1; i++) {
            if(!flag[s[i] - 'a'] && i != 0) continue;
            vector<int> vis(26, 0);
            int rhs = i;
            while(rhs < len){
                vis[s[rhs] - 'a']++;
                if(check(vis)){
                    result = max<int>(result, rhs - i + 1);
                }
                rhs++;
            }
            for(int i = 0; i < vis.size(); i++){
                if(vis[i] > 0 && vis[i] < k){
                    flag[i] = false;
                } else if(vis[i] >= k){
                    flag[i] = true;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    auto vec = sol.longestSubstring("ababbc", 2);
    cout << vec << endl;
    return 0;
}
// 单词拆分
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(const auto& x : wordDict){
            se.insert(x);
        }
        vector<bool> dp(se.size() + 10, false);
        dp[0] = true; // 为了使得第一个子问题成立
        for(size_t i = 1; i <= s.size(); i++){
            for(size_t j = 0; j < i; j++){
                if(dp[j] && se.find(s.substr(j, j-i)) != se.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    vector<string> vec = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    Solution sol;
    cout << sol.wordBreak(str, vec) << endl;
    return 0;
}
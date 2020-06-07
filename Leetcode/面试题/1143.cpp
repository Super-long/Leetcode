// 最长公共子序列 还有一个最长重复子数组 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1010][1010];
        memset(dp, 0, sizeof dp);
        for(size_t i = 1; i <= text1.size(); i++){
            for(size_t j = 1; j <= text2.size(); j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        for(int i = 0; i<=text1.size();++i){
            for(int j = 0; j<=text2.size();++j){
                cout << dp[i][j] << " ";
            }
            putchar('\n');
        }
        return dp[text1.size()][text2.size()];
    }
};

int main(){
    Solution sol;
    cout << sol.longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}
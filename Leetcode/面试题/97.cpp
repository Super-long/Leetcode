// 交错字符串
#include <bits/stdc++.h>
using namespace std;

class Solution {     //
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int n = s1.size();
        int m = s2.size();
        dp[0][0] = 1;
        if(m + n != s3.size()){
            return false;
        }
        // 从零开始是因为要考虑到一个为0另一个大于零
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                int t = i + j -1;
                if(i > 0){
                    dp[i][j] |= (s1[i - 1] == s3[t] && dp[i-1][j]);
                }
                if(j > 0){
                    dp[i][j] |= (s2[j - 1] == s3[t] && dp[i][j-1]); 
                }
            }
        }
        return dp[n][m];
    }
};
// 最长重复子数组 还有一个类似的最长公共子序列
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int dp[1010][1010];
        memset(dp, 0, sizeof dp);
        int res = 0;
        for(size_t i = 1; i <= A.size(); i++){
            for(size_t j = 1; j <= B.size(); j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
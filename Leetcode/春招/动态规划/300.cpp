#include <bits/stdc++.h>
using namespace std;

class Solution {    // 最长上升子序列，354是用二分的优化版本
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (size_t i = 0; i < nums.size(); i++){
            for (size_t j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
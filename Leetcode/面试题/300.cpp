//lis 最长上升子序列 
/**
 * dp[i] = max(dp[j]) + 1;
 * j < i;
 * nums[j] < nums[i]
*/
//不但可以拿dp做 也可以贪心+二分 达到nlogn的复杂度
#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int dp[1000000];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(size_t i = 0; i < nums.size(); i++){
            dp[i] = 1;
            int Max = 0;
            for(size_t j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    Max = std::max(Max, dp[j]);
            }
            dp[i] = Max + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
}; */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = 1;
        int d[10000]; 
        memset(d, 0 ,sizeof(d));
        d[len] = nums[0];

        for(size_t i = 1; i < nums.size(); i++){
            if(nums[i] > d[len]) d[++len] = nums[i]; //这里的d数组总是单调的
            int* spot = std::lower_bound(d, d+len, nums[i]);
            *spot = nums[i]; //lower_bound才能过 见下样例
        }
        return len;
    }
};

/**
 * [4,10,4,3,8,9]
 * upper_bound会返回大于参数的第一个值 就导致4出现在d数组的两个参数上
*/

int main(){
    vector<int> vec{10,9,2,5,3,7,101,18};
    Solution sol;
    cout << sol.lengthOfLIS(vec) << endl;
    return 0;
}
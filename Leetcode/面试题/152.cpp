// 乘积最大子数组
#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    int maxProduct(vector<int>& nums) { // 自己写的错误解法 {-2,3,-4} 
        if(!nums.size()) return 0;
        int dp[nums.size()+10];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1]*nums[i], nums[i]);
        }
        long long result = LONG_MIN;
        for(int i=0;i<nums.size();++i){
            result = max(result, static_cast<long long>(dp[i]));
        }
        return result;        
    }
}; */

class Solution {
public:
    int maxProduct(vector<int>& nums) { 
        vector <int> maxF(nums), minF(nums);
        maxF[0] = nums[0]; minF[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxF[i] = max(maxF[i-1]*nums[i], max(minF[i-1]*nums[i], nums[i]));
            minF[i] = min(minF[i-1]*nums[i], min(maxF[i-1]*nums[i], nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

int main(){
    Solution sol;
    vector<int> vec = {2,3,-2,4};
    cout << sol.maxProduct(vec) << endl;
    return 0;
}
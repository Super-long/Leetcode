//按摩师
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        if(!nums.size()) return 0;
        else if(nums.size()==1) return nums[0];
        else if(nums.size()==2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), -1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return dp[nums.size()-1];
    }
};

int main(){
    Solution sol;
    vector<int> vec = {4,1,2};
    cout << sol.massage(vec) << endl;
    return 0;
}
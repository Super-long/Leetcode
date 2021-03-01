#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i];
            if(i && nums[i] == nums[i - 1]) continue;    
            for (int j = i + 1; j < nums.size(); ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; // 防止类似与[-1,-1,2]这种答案
                target += nums[j];
                int rhs = nums.size() - 1;
                while(j < rhs && target + nums[rhs] > 0){
                    rhs--;
                }
                if(j == rhs) break;
                if(target + nums[rhs] == 0){
                    res.push_back({nums[i], nums[j], nums[rhs]});
                }
                target -= nums[j];
            }
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 3; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int sum_top = target - nums[i];
            for (int j = i + 1; j < nums.size() - 2; j++){  // 至少j后面两个值才有意义
                if(j != i+1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int sum_bottom = sum_top - nums[j];
                int lhs = j + 1;
                int rhs = nums.size() - 1;
                while(lhs < rhs){ 
                    if(nums[lhs] + nums[rhs] == sum_bottom){
                        res.push_back({nums[i], nums[j], nums[lhs], nums[rhs]});
                        while(lhs < rhs && nums[lhs] == nums[lhs + 1]){
                            ++lhs;
                        }
                        ++lhs;
                        while (lhs < rhs && nums[rhs] == nums[rhs - 1]){
                            --rhs;                            
                        }
                        --rhs;
                    } else if(nums[lhs] + nums[rhs] < sum_bottom){
                        ++lhs;
                    } else {
                        --rhs;
                    }
                }
            }
            
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1, 0, -1, 0, -2, 2};
    auto res = sol.fourSum(vec, 0);
    for(auto item : res){
        for(size_t i = 0; i < item.size(); i++){
            cout << item[i] << " ";
        }
        putchar('\n');
    } 
    return 0;
}
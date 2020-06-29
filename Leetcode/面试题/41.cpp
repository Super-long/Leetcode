// 缺失的第一个正数
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size()) return 1;
        for(auto& x : nums){
            if(x <= 0){
                x = nums.size() + 1;
            }
        }
        for(size_t i = 0; i < nums.size(); i++){
            if(abs(nums[i]) <= nums.size()){
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        for(size_t i = 0; i < nums.size(); i++){
            //cout << nums[i] << endl;
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main(){
    Solution sol;
    // 3,4,-1,1 ------ 7,8,9,11,12
    vector<int> vec = {3,4,-1,1};
    cout << sol.firstMissingPositive(vec) << endl;
    return 0;
}
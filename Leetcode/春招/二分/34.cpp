#include <bits/stdc++.h>
using namespace std;

class Solution {        // 经典题目；求一个数字的两个区间；
private:
    // true的时候求左边
    int binarySearch(vector<int>& nums, int target, bool flag) {
        int left = 0, right = nums.size() - 1;
        int ans = static_cast<int>(nums.size());

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target || (flag && nums[mid] >= target)){
                right = mid - 1;    // 为了跳出while循环
                ans = mid;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lhs = binarySearch(nums, target, true);
        int rhs = binarySearch(nums, target, false) - 1;    // 得到的总是target的下一位

        // 前两个条件去除掉超出界限的情况；最后一个条件去除范围内没找到的情况；
        if(lhs == nums.size() || (lhs == 0 && nums[0] != target) || (nums[lhs] != target && nums[rhs] != target)){ 
            return {-1, -1};
        }
        return {lhs, rhs};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    auto temp = sol.searchRange(nums, 9);
    for(auto x : temp){
        cout << x << " ";
    } 
    return 0;
}
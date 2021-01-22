#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    /*
     * @notes: flag为true代表求左区间，false代表右区间
     */
    int findIndex(vector<int>& nums, int target, bool flag){
        int lhs = 0;
        int rhs = nums.size() - 1;
        int ans = nums.size();
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs)/2;
            // 不管左区间还是右区间都在左边；仅 flag=true 时在左区间
            if((nums[mid] > target ) || (flag && nums[mid] >= target)){
                rhs = mid - 1;
                ans = mid;  // 右区间的答案更新
            } else {
                lhs = mid + 1;  // 答案不可能是mid，因为nums[mid] > target，我们要找一个和target相等的值
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lhs = findIndex(nums, target, true);
        int rhs = findIndex(nums, target, false) - 1;

        // 前两个条件去除掉超出界限的情况；最后一个条件去除范围内没找到的情况；
        if(lhs == nums.size() || (lhs == 0 && nums[0] != target) || (nums[lhs] != target && nums[rhs] != target)){ 
            return {-1, -1};
        }
        return {lhs, rhs};
    }
};
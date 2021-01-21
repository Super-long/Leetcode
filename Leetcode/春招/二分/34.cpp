#include <bits/stdc++.h>
using namespace std; 

// https://blog.csdn.net/qq_19332527/article/details/99881418?ops_request_misc=%25257B%252522request%25255Fid%252522%25253A%252522161123902516780271564210%252522%25252C%252522scm%252522%25253A%25252220140713.130102334.pc%25255Fall.%252522%25257D&request_id=161123902516780271564210&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-3-99881418.first_rank_v2_pc_rank_v29&utm_term=%E4%BA%8C%E5%88%86%E4%B8%AD%E5%A4%A7%E4%BA%8E%E5%92%8C%E5%A4%A7%E4%BA%8E%E7%AD%89%E4%BA%8E

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
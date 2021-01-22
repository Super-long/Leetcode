#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        int ans = nums.size();  // 防止一个大于数组最大值的数字，这样答案就成零0
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(nums[mid] >= target){
                rhs = mid - 1;
                ans = mid;
            } else {
                lhs = mid + 1;
            }
        }
        return ans;
    }
};

// 得到的ans就是该顺序插入的位置或者那个数本身

int main(){
    Solution sol;
    vector<int> sum = {1,3,5,6};
    cout << sol.searchInsert(sum, -1) << endl;
    return 0;
}
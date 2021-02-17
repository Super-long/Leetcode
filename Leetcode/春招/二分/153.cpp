#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {    // 
        int lhs = 0;
        int rhs = nums.size() - 1;
        int ans = rhs + 1;
        while(lhs < rhs){
            cout << lhs << " " << rhs << endl;
            int mid = lhs + (rhs - lhs)/2;

            if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];   // 倒序
            }

            if(nums[mid] > nums[rhs]){
                lhs = mid + 1;
            } else {
                ans = mid;
                rhs = mid;  // 整个二分规则建立在答案在区间之内的情况下，所以不能减1，while也不能加等号
            }
        }
        if(ans == nums.size()) return nums[0];  // 顺序
        return nums[ans];
    }
};

int main(){
    Solution sol;
    vector<int> vec = {2,1};
    cout << sol.findMin(vec) << endl;
    return 0;
}
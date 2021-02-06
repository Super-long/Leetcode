#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int mid, vector<int>& nums){   // true代表答案在左边
        int lhs = mid;
        int rhs = mid;
        if(mid + 1 >= nums.size()) {    // 第一遍没考虑到
            return true;
        }
        if(nums[mid + 1] == nums[mid]){
            rhs = mid + 1;
        } else {
            lhs = mid - 1;
        }   // 当然可能mid 就是落单的值
        if((nums.size() - rhs)&1){
            return true;
        } else {
            return false;
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        int ans = nums.size();
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(check(mid, nums)){
                cout << "left\n";
                rhs = mid - 1;
                ans = mid;
            } else {
                cout << "right\n";
                lhs = mid + 1;
            }
        }
        return nums[ans];
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1};
    cout << sol.singleNonDuplicate(vec) << endl;
    return 0;
}
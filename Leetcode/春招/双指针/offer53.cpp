#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int mid, const vector<int>& nums){
        if(nums[mid] > mid){
            return true;
        } else {
            return false;
        }
    }
public:
    int missingNumber(vector<int>& nums) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        int ans = nums.size();
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(check(mid, nums)){
                ans = mid;
                rhs = mid - 1;
            } else {
                lhs = mid + 1;
            }
        }
        return ans;
    }
};
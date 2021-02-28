#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        while(lhs < rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(nums[mid] > nums[rhs]){
                lhs = mid + 1;
            } else if(nums[mid] < nums[rhs]){
                rhs = mid;
            } else {
                rhs--;
            }
        }
        return nums[rhs];
    } 
};
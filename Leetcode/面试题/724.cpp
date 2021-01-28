#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int now = 0;
        for (size_t i = 0; i < nums.size(); i++){
            if(now == sum - nums[i]) return i;
            now += nums[i];
        }
        return -1;
    }
};
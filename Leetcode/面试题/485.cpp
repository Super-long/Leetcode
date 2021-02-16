#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int lhs = 0;
        int ans = 0;
        for (size_t i = 0; i < nums.size(); i++){
            if(nums[i]){
                ans = max<int>(ans, i - lhs + 1);
            } else {
                lhs = i + 1;
            }
        }
        return ans;
    }
};
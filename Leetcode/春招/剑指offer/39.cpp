#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(!nums.size()) return 0;
        int target = nums[0];
        int count = 1;
        for (size_t i = 1; i < nums.size(); i++){
            if(nums[i] == target){
                count++;
            } else {
                count--;
                if(!count && i < nums.size() - 1){
                    target = nums[i+1];
                }
            }
        }
        return target;
    }
};
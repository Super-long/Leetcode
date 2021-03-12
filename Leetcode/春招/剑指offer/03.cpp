#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bitset<100000> bt;
        for (size_t i = 0; i < nums.size(); i++){
            if(bt[nums[i]] == 1){
                return nums[i];
            }
            bt.set(nums[i]);
        }
        return -1;
    }
};
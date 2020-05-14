// 只出现一次的数字
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        //for (auto e: nums) ret ^= e;
        for(int i=0;i<nums.size();i++){
            ret^=nums[i];
        }
        return ret;
    }
};

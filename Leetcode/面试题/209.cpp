// 长度最小的子数组
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(!nums.size()) return 0;
        int lhs = 0, rhs = 0;
        vector<int> pre(nums.size(), 0);    // 前缀数组
        pre[0] = nums[0];
        for(size_t i = 1; i < nums.size(); i++){
            pre[i] = pre[i - 1] + nums[i];
        }
        int res = 0x3f3f3f3f;
        while(rhs != nums.size()){
            int Temp = 0;
            if(lhs != 0) Temp = pre[lhs - 1];
            if(pre[rhs] - Temp >= s){
                res = min(rhs - lhs + 1, res);
                ++lhs;
            } else {
                ++rhs;
            }
        }
        if(res == 0x3f3f3f3f) res = 0;
        return res;
    }
};
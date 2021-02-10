#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int lhs = 0;
        int res = 0;
        int item = 1;
        if(k == 0) return 0;    // 零很特殊，因为我们把item设置为1了
        for (size_t i = 0; i < nums.size(); i++){
            item *= nums[i];

            while(item >= k && lhs <= i){
                item /= nums[lhs];
                lhs++;
            }   // 区间总乘积小于k
            res += i - lhs + 1;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,1,1};
    cout << sol.numSubarrayProductLessThanK(vec, 1) << endl;
    return 0;
}
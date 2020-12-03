#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {  // 第一遍傻逼了，一般这些题每次右边移一次，左边循环；
        int lhs = 0;
        int rhs = 0;
        int res = INT_MAX;
        int sum = 0;
        while(rhs < nums.size()){
            sum += nums[rhs];
            while(sum >= s){
                res = min(res, rhs - lhs + 1);
                sum -= nums[lhs];
                lhs++;
            }
            rhs++;
        }
        cout << res << " " << INT_MAX << endl;
        if(res == INT_MAX) return 0;
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1};
    cout << sol.minSubArrayLen(3 , nums) << endl;
    return 0;
}
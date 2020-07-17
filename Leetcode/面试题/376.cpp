// 摆动序列
#include <bits/stdc++.h>
using namespace std;

class Solution {    // 直接匹配不一定是最优的 比如1,3,1,3,4,5,4,5
private:    // 状态转移 
    constexpr static const int UP = 0;
    constexpr static const int DOWN = 1;
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int op = -1;    // 预期的下一步操作 -1为特殊值
        int res = 1;
        for(size_t i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1] && op != DOWN){
                res++;
                op = DOWN;
            }else if(nums[i] < nums[i-1] && op != UP){
                res++;
                op = UP;
            } // 等于的情况和其他不满足的情况 i递增 
        }
        return res;
    }
};

/* class Solution { // dp
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(!nums.size()) return 0;
        int up = 1;
        int down = 1;
        for(size_t i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] > 0){
                up = down + 1;
            }else if(nums[i] - nums[i-1] < 0){
                down = up + 1;
            }
        }
        return max(up, down);
    }
}; */

int main(){
    Solution sol;
    vector<int> vec = {1,2,3,4,5,6,7,8,9}; 
    cout << sol.wiggleMaxLength(vec) << endl;
    return 0;
}
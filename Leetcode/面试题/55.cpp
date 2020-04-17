// 跳跃游戏
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0) return true;
        int target = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i <= target){
                target = max(nums[i]+i, target);
                if(target >= nums.size() - 1)
                    return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> pool = {3,2,1,0,4};
    cout << sol.canJump(pool) << endl;
    return 0;
}
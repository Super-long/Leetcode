#include <bits/stdc++.h>
using namespace std;

/* class Solution {
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
}; */

/* class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int lhs = 0;
        int rhs = 0;
        int res = INT_MAX;  // INT_MAX是一个缺陷，因为有可能答案就是INT_MAX
        int sum = 0;
        while(rhs < nums.size() && lhs <= rhs){
            sum += nums[rhs];
            cout << lhs << " " << rhs << endl;
            while(sum >= s){
                res =  min(res, rhs - lhs + 1);
                sum -= nums[lhs++];
            }
            rhs++;
        }
        return res == INT_MAX ? 0 : res;
    }
}; */

// 这题还可以用二分+前缀和在NlogN解
class Solution {
private:
    vector<int> prev;
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        prev.resize(nums.size());
        int pre = 0;
        for(int i = 0; i < nums.size(); ++i){
            prev[i] = pre + nums[i];
            cout << prev[i] << " ";
            pre = prev[i];
        }
        putchar('\n');
        int res = INT_MAX;
        for (size_t i = 0; i < prev.size(); i++){
            auto itear = lower_bound(prev.begin(), prev.end(), prev[i] + s - nums[i]);  // 迭代器相减begin()得到的其实是后者的下标
            if(itear == prev.end()) continue;
            int interval = itear - prev.begin() - i + 1;
            res = min(res, interval);
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    cout << sol.minSubArrayLen(7, nums) << endl;
    return 0;
}
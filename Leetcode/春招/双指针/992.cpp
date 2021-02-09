#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getK(const vector<int>& nums, int K){
        int lhs = 0;
        int rhs = 0;
        unordered_map<int, int> vis;
        int res = 0;
        while(rhs < nums.size()){
            vis[nums[rhs]]++;
            while(vis.size() > K){
                vis[nums[lhs]]--;
                if(vis[nums[lhs]] == 0){
                    vis.erase(nums[lhs]);
                }
                lhs++;
            }   // 当前子数组中不同的值小于等于K
            res += rhs - lhs + 1;   // 这里才是这道题最难的地方，想看出可以这样更新不容易，求区间内子数组总数可以这样求
            rhs++;
        } 
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return getK(A, K) - getK(A, K - 1);
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,1,3,4};
    cout << sol.subarraysWithKDistinct(vec, 3) << endl;
    return 0;
}
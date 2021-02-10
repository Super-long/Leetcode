#include <bits/stdc++.h>
using namespace std;

class Solution {    // 最长递增子序列，dp，二分都可以解
public:
    int lengthOfLIS(vector<int>& nums) {
        int lhs = 0;
        int rhs = 0;
        vector<int> res;
        for (size_t i = 0; i < nums.size(); i++){
            lhs = 0;
            rhs = res.size() - 1;
            int ans = res.size();
            while(lhs <= rhs){
                int mid = lhs + (rhs - lhs)/2;
                if(res[mid] >= nums[i]){ // 寻找比nums[i]小的最大值
                    rhs = mid - 1;
                    ans = mid;
                } else {
                    lhs = mid + 1;
                }
            }
            if(ans == res.size()){
                cout << ans  << " " << nums[i] << endl;
                res.push_back(nums[i]);
            } else {
                cout << ans << " : " << nums[i] << endl;
                res[ans] = nums[i];
            }
        }
        return res.size();
    }
};

/*
int q[10000];
int len = 0;
for(int i = 0; i < nums.size(); i ++){
        int l = 0, r = len;
        while(l < r){                   //二分找到一个最大的小于当前数的数。
            int mid = l + r + 1 >> 1;
            if(q[mid] < nums[i]) l = mid;
            else r = mid - 1;
        }
        q[r + 1] = nums[i];
        if(r + 1 > len) len ++;
}
return len;
*/

int main(){
    Solution sol;
    vector<int> vec = {0,1,0,3,2,3};
    cout << sol.lengthOfLIS(vec) << endl;
    return 0;
}
// 和为k的子数组
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 暴力
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end]; //因为数组中有负数 所以在得到结果以后还是要继续
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
}; */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0,pre = 0;
        unordered_map<int, int> mp;
        mp[0] = 1; //为什么
        for(int i=0;i<nums.size();++i){
            pre = pre+nums[i];
            res += mp[pre-k];
            mp[pre]++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1};
    cout << sol.subarraySum(vec, 1) << endl;
    return 0;
}
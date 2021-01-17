// 统计「优美子数组」
#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> pool;
        pool.push_back(-1);
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]&1) pool.push_back(i);
        }
        if(pool.size() < k) return 0;
        int lhs = 1, rhs = k;
        int res = 0;
        pool.push_back(nums.size());
        while(rhs < pool.size()-1){
            res += (pool[lhs] - pool[lhs-1]) * (pool[rhs+1] - pool[rhs]);
            cout << res << endl;
            lhs++; rhs++;
        }
        return res;
    }
};

/* class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int odd[n + 2], ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) odd[++cnt] = i;
        }
        odd[0] = -1, odd[++cnt] = n;
        for (int i = 1; i + k <= cnt; ++i) {
            cout << i+k << endl;
            ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]); 
        }
        return ans;
    }
}; */

int main(){
    Solution sol;
    vector<int> res = {1,1,2,1,1};
    cout << sol.numberOfSubarrays(res, 3) << endl;
    return 0;
}
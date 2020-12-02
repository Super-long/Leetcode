#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> vec(nums.size());
        if(vec[0] & 1) vec[0] = 1;
        for (size_t i = 1; i < nums.size(); i++){   // 包含此下标前面的偶数总数
            vec[i] = vec[i - 1];
            if(!(nums[i] & 1)){
                vec[i]++;
            }
        }
        

        int lhs = 0;
        int rhs = 0;

        int res = 0;
        int num = 0;
        
        while(rhs < nums.size()) {
            if(nums[rhs] & 1){ // 奇数
                ++num;
            }
            ++rhs;
            //cout << num << endl;
            if(num == k){
                //cout << lhs << " " << rhs << endl;
                ++res;
                if(nums[lhs] & 1){
                    --num;
                }
                ++lhs;
                
            }
        }
        return res;
    }
}; */

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k){    // 这题感觉完全没有必要拿双指针做，把每个奇数的下标择出来就可以了，就是这样做
        vector<int> odd;
        odd.push_back(-1);

        int ans = 0;
        int i = 1;
        for (int j = 0; j <= nums.size(); j++)
        {
            if (j == nums.size() || (nums[j] & 1))
            {
                odd.push_back(j);
            }

            if (odd.size() - i > k)
            {
                int left = odd[i] - odd[i - 1];
                int right = j - odd[odd.size() - 2];    // 这里j其实就是odd[odd.size() - 1]
                ans += left * right;
                i++;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {2,2,2,1,2,2,1,2,2,2};
    cout << sol.numberOfSubarrays(vec, 2) << endl;
    return 0;
}
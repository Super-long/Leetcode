// 求逆序数
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergesort(vector<int>& nums, vector<int>& res, int lhs, int rhs){
        if(lhs >= rhs) return 0;

        int mid = (lhs+rhs)/2;
        int count = mergesort(nums, res, lhs, mid) + mergesort(nums, res, mid+1, rhs);
        int i  = lhs, j = mid + 1, pos = lhs;
        while(i <= mid && j <= rhs){ // 两个区间有序
            if(nums[i] <= nums[j]){
                res[pos] = nums[i];
                ++i;
                count += (j - (mid + 1)); // 上一个值的贡献度
            } else {
                res[pos] = nums[j];
                ++j;
            }
            ++pos;
        } // res数组中填充了pos-lhs个值 

        // 两个循环只跑一个
        for (int k = i; k <= mid; ++k) {
            res[pos++] = nums[k];
            count += (j - (mid + 1));
        }
        for (int k = j; k <= rhs; ++k) {
            res[pos++] = nums[k];
        }
        // 拷贝只会拷[lhs,rhs-1]过去
        copy(res.begin() + lhs, res.begin() + rhs + 1 , nums.begin() + lhs);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> res(nums.size());
        return mergesort(nums, res, 0, nums.size() - 1);
    }
};

int main(){
    Solution sol;
    vector<int> vec = {7,5,6,4};
    cout << sol.reversePairs(vec) << endl;
    for(auto x : vec){
        cout << x << " ";
    }
    return 0;
}
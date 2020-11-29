#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int calculate(vector<int>& nums, int lhs, int rhs){ // 第一遍没有考虑等于的情况，oj里面的第二次提交
        if(lhs >= rhs){
            return 0;
        }
        int mid = (lhs + rhs) / 2;
        int n1 = calculate(nums, lhs, mid);
        int n2 = calculate(nums, mid + 1, rhs);
        int res = n1 + n2;

        sort(nums.begin() + lhs, nums.begin() + mid + 1);
        sort(nums.begin() + mid + 1, nums.begin() + rhs + 1);

        int index = mid + 1; // 描述第二个区间的下标
        for (size_t i = lhs; i <= mid;){
            if(index > rhs) break;
            long int a = nums[i];
            long int b = nums[index];
            b *= 2;
            if(a > b){
                res += mid - i + 1;
                ++index;
            } else {
                i++;
            }
        }
        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        return calculate(nums, 0 , nums.size() - 1);
    }
};

int main(){
    vector<int> nums = {1,3,2,3,1};
    Solution sol;
    cout << sol.reversePairs(nums) << endl;
    return 0;
}
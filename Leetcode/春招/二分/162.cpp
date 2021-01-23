#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        int ans = nums.size();
        nums.push_back(INT_MIN);    // 为了避免mid+1越界
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(nums[mid] > nums[mid + 1]){
                rhs = mid - 1;
                ans = mid;
            } else {
                lhs = mid + 1;
            }
        }
        if(ans >= nums.size() - 1) ans-=1;  // 最后有一个样例[-2147483648]（擦第10行屁股）
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> vec = {1};
    cout << sol.findPeakElement(vec) << endl;
    return 0;
}
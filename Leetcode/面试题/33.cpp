// 搜索旋转排序数组

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid]){ //O(1)判断左侧有序 等于的时候保证左侧有序
                if(nums[0] <= target && target < nums[mid]){ //target在左侧
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(nums[mid] < target && target <= nums[nums.size() - 1]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }   
        return -1;
    }
};

int main(){
    vector<int> res = {3,1};
    Solution sol;
    cout << sol.search(res, 1) << endl;
    return 0;
}
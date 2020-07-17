// 搜索插入位置
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
/*         for(int i = nums.size()-1; i >= 0; i--){
            if(target == nums[i]){
                return i;
            }else if (target > nums[i]){
                return i + 1;
            }
        }
        return 0; */
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,3,5,6};
    cout << sol.searchInsert(vec, 0) << endl;
    return 0;
}
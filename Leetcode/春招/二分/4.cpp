#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    // 查找这两个数组内第k小的值
    double getNumberKValue(vector<int>& nums1, vector<int>& nums2, int k){
        int index1 = 0; // nums1下标
        int index2 = 0; // nums2下标
        int rhsnums1 = nums1.size();
        int rhsnums2 = nums2.size();
        while(true){
            if(index1 == rhsnums1){
                return nums2[index2 + k - 1];
            } else if(index2 == rhsnums2){  // 两种边界情况，一边数组为空
                return nums1[index1 + k - 1];
            } else if(k == 1){              // k == 1,返回两个数组起始的最小值
                return min(nums1[index1], nums2[index2]);
            } else {
                int temp_index = k/2;
                int lhs = index1 + temp_index - 1;  // 从index1开始有temp_index个值，lhs是第temp_index个
                int rhs = index2 + temp_index - 1;

                if(lhs >= rhsnums1){
                    lhs = rhsnums1 - 1; // 越界以后放到最后一位
                }
                if(rhs >= rhsnums2){
                    rhs = rhsnums2 - 1;
                }

                if(nums1[lhs] <= nums2[rhs]){   // lhs 以前的值完全可以放弃
                    k -= min(temp_index, lhs - index1 + 1);
                    index1 = lhs + 1;
                } else {
                    k -= min(temp_index, rhs - index2 + 1);
                    index2 = rhs + 1;
                }
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        auto res = getNumberKValue(nums1, nums2, len / 2 + 1);
        if(len&1){
            return res;
        } else {
            return (res + getNumberKValue(nums1, nums2, len / 2)) / 2;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1};
    vector<int> nums2 = {2,3,4,5,6};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
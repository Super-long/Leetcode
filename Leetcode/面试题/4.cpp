// 寻找两个正序数组的中位数

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findKNumber(int K, vector<int>& nums1, vector<int>& nums2){
        int len1 = nums1.size();
        int len2 = nums2.size();

        int index1 = 0, index2 = 0;

        while(true){
            if(index1 == len1){
                return nums2[index2+K-1];
            } else if(index2 == len2){
                return nums1[index1+K-1];
            } else if(K == 1){
                return min(nums1[index1], nums2[index2]);
            }

            int newindex1 = min(K/2+index1-1, len1-1); // 防止k/2越界 减一是因为里面比较下标
            int newindex2 = min(K/2+index2-1, len2-1);

            if(nums1[newindex1] <= nums2[newindex2]){
                K -= (newindex1-index1+1);
                index1 = newindex1+1;
            } else {
                K -= (newindex2-index2+1);
                index2 = newindex2+1;
            } 
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size()+nums2.size();
        if(len&1)
            return findKNumber(len/2+1, nums1, nums2);
        else 
            return double((findKNumber(len/2+1, nums1, nums2)+findKNumber(len/2, nums1, nums2)))/2;
    }
};

int main(){
    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = {6,7,8,9,10};
    Solution sol;
    cout << sol.findMedianSortedArrays(vec1, vec2) << endl;
    return 0;
}
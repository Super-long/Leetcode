#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findKthFromRange(vector<int>& nums, int lhs, int rhs, int k){
        int index = randomPartition(nums, lhs, rhs);
        if(index == k){
            return nums[index];
        } else {
            return index < k ? findKthFromRange(nums, index + 1, rhs, k) : findKthFromRange(nums, lhs, index - 1, k);
        }

    }

    int randomPartition(vector<int>& nums, int lhs, int rhs){
        int index = rand() % (rhs - lhs + 1) + lhs;
        swap(nums[index], nums[rhs]);
        return Partition(nums, lhs, rhs);
    }

    // 光芒四射的函数
    int Partition(vector<int>& nums, int lhs, int rhs){ 
        int x = nums[rhs];
        int index = lhs - 1;
        for (int i = lhs; i < rhs; i++){
            if(nums[i] <= x){
                swap(nums[++index], nums[i]);
            }
        }
        swap(nums[index + 1], nums[rhs]);
        return index + 1;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return findKthFromRange(nums, 0, nums.size() -1, nums.size() - k);  // 最后一个参数也是比较巧妙
    }
};


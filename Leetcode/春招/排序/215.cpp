#include <bits/stdc++.h>
using namespace std;

class Solution {    // 经典题目，快速选择；当然最小堆，最大堆，计数排序都可
private:
    int quickSelect(vector<int>& nums, int lhs, int rhs, int index){
        int mid = RandomPartition(nums, lhs, rhs);
        if(mid == index){
            return nums[mid];
        } else {
            return mid < index ? quickSelect(nums, mid + 1, rhs, index) : quickSelect(nums, lhs, mid - 1, index);
        }
    }

    int RandomPartition(vector<int>& nums, int lhs, int rhs){
        int i = rand()%(rhs - lhs + 1) + lhs;
        swap(nums[i], nums[rhs]);   // rhs上的元素就是划分点
        int index = Partition(nums, lhs, rhs);
        cout << lhs << " " << rhs << endl;
        for(auto x : nums) cout << x << " ";
        putchar('\n');
        return index;
    }

    int Partition(vector<int>& nums, int lhs, int rhs){
        int base = nums[rhs];
        int index = lhs;
        for (size_t i = lhs; i < rhs; i++){
            if(nums[i] <= base){
                swap(nums[i], nums[index++]);
            }
        }
        swap(nums[index], nums[rhs]);
        return index;   // 第一遍这里写错了
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0)); // 设置随机种子
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main(){
    Solution sol;
    vector<int> vec = {3,2,3,1,2,4,5,5,6};
    cout << sol.findKthLargest(vec, 4) << endl;
    return 0;
}
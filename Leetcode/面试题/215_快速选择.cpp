// 数组中的第K个最大元素
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int q = FindKbetweenLAndR(nums, 0, nums.size() - 1, nums.size() - k);
        return q;
    }

    int Partition(vector<int>& nums, int l, int r){
        int q = rand() % (r - l + 1) + l;
        swap(nums[q], nums[r]);
        int x = nums[r];
        int i = l - 1;
        for(int j = l; j < r; ++j){
            if(nums[j] < x){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int FindKbetweenLAndR(vector<int>& nums, int l, int r, int index){
        int q = Partition(nums, l ,r); // q是数组partition的地方
        if(q == index){
            return nums[q];
        } else {
            return q < index ? FindKbetweenLAndR(nums, q + 1, r, index) :
                FindKbetweenLAndR(nums, l, q - 1, index); 
        }
    }
};

int main(){
    Solution sol;
    vector<int> vec = {3,2,1,5,6,4};
    cout << sol.findKthLargest(vec, 2) << endl;
    return 0;
}
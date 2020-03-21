#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]); //把中间数换到中间去
        return i + 1;
    }

    int random_partition(vector<int>& nums, int l, int r){
        int i = rand()%(r-l+1)+l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    void quick_select(vector<int>& nums, int l, int r, int k){
        if(l >= r) return;
        int pos = random_partition(nums, l ,r); //得到随机得到的那个数一轮排序后的下标
        int sum = pos-l+1;
        if(sum == k) return;
        else if(sum < k) quick_select(nums, l+sum, r, k-sum);
        else quick_select(nums, l, pos-1, k);
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        quick_select(arr, 0 ,arr.size()-1, k);
        vector<int>vec;
        for (int i = 0; i < k; ++i) vec.push_back(arr[i]);
        return vec; 
    }
};

int main(){
    Solution sol;
    vector<int> vec={3,2,1};//4,5,1,6,2,3,7,8
    auto pool = sol.getLeastNumbers(vec, 2);
    for(auto x : pool){
        cout << x << " ";
    }
    return 0;
}
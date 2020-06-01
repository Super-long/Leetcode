// 峰与谷
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 排序
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec;
        int lhs = 0, rhs = nums.size() - 1;
        while(lhs < rhs){
            vec.push_back(nums[rhs]);
            vec.push_back(nums[lhs]);
            lhs++; rhs--;
        }
        if(nums.size()&1) vec.push_back(nums[lhs]);
        nums = vec;
    }
}; */

class Solution {
public:
    // 相当于一个传递的关系  
    void wiggleSort(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(i%2==0){// 偶数为峰
                if(nums[i]<nums[i-1]) swap(nums[i],nums[i-1]);
            }
            else{ // 奇数为谷
                if(nums[i]>nums[i-1]) swap(nums[i],nums[i-1]);
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> vec = {5,3,1,2,3};
    sol.wiggleSort(vec);
    for(auto x : vec){
        cout << x << " ";
    }
    return 0;
}
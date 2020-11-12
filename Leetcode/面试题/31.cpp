#include <bits/stdc++.h>
using namespace std;

class Solution { // 这题感觉和脑筋急转弯一样;有重复的值也是可解的。
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size();
        for (int i = index - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                index = i - 1;
                break;
            }
        }

        if(index == nums.size()){
            sort(nums.begin(), nums.end(), less<int>());
            return;
        }

         for (int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > nums[index]){
                swap(nums[index], nums[i]);
                break;
            }
        }
        sort(nums.begin() + index + 1, nums.end());
        return;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1, 5, 1};
    sol.nextPermutation(vec);
    for (auto x : vec){
        cout << x << " ";
    }
    return 0;
}
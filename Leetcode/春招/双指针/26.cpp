#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lhs = 0;
        int rhs = 0;
        int len = nums.size();
        int res = 0;
        while(rhs < len){
            nums[lhs++] = nums[rhs];
            ++res;
            if(rhs + 1 == len) rhs+=1;
            while(rhs + 1 < len && nums[rhs + 1] == nums[rhs++]);
        }
        if(lhs - 2 >= 0 && nums[lhs - 2] == nums[lhs - 1]){
            res--;
        }
        return res;
    }
};

/* class Solution {
public:
    int removeDuplicates(vector<int>& nums) {   // 题解太优雅了
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
}; */


int main(){
    Solution s;
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(vec) << endl;
    for (size_t i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    putchar('n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std; 

class Solution {
public: 
    int removeDuplicates(vector<int>& nums) {
        int lhs = 0;
        int flag = 1;
        for (size_t i = 1; i < nums.size(); i++){
            if(flag < 2 && nums[i] == nums[lhs]){
                flag++;
                lhs++;
            } else if(flag <= 2 && nums[i] != nums[lhs]){
                flag = 1;
                lhs++;
            }
            nums[lhs] = nums[i];
        }
        return lhs + 1;
    }
};

int main(){
    Solution s;
    vector<int> vec = {0,0,1,2,2,3,3,4};
    cout << s.removeDuplicates(vec) << endl;
    for (size_t i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    putchar('n');
    return 0;
}
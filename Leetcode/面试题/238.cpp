//除自身以外数组的乘积
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = 1;
        // 奇了怪了,把size_t改为int就对了
        for(int i = 1; i < nums.size(); i++){
            cout << i << endl;
            res[i] = res[i-1] * nums[i-1];
        }
        int right = 1;
        size_t t = nums.size() - 1;
        cout << t << endl;
        for(size_t i = nums.size()-1; i >= 0 ; i--){
            cout << i << endl;
            getchar();
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};

/* class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            answer[i] = answer[i] * R;
            R *= nums[i];
        }
        return answer;
    }
};
 */

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    auto item = sol.productExceptSelf(nums);
    for(auto x : item){
        cout << x << endl;
    }
    return 0;
}
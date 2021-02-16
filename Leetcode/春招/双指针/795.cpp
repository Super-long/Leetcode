#include <bits/stdc++.h>
using namespace std;

class Solution {    // 特殊的双指针，题解用了一种更骚的方法
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int lhs = 0;
        int ans = 0;
        int index = 0;
        bool flag = true;
        auto check = [&](int para) -> bool{
            if(para >= L && para <= R) return true;
            return false;
        };
        for(size_t i = 0; i < A.size(); i++){
            if(check(A[i])){
                ans += i - lhs + 1;
                index = i;  // 记录存储在区间内的最后一个下标
                flag = false;
            } else if(A[i] > R){
                lhs = i + 1;
                flag = true;
            } else {
                if(flag) continue;
                ans += index - lhs + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> sum = {73,55,36,5,55,14,9,7,72,52};
    cout << sol.numSubarrayBoundedMax(sum, 32, 69) << endl;
    return 0;
}
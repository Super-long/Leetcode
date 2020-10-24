#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 没处理全是负数的情况，想少了
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        size_t index = 0;
        int lhs = 0;
        int rhs = 0;
        for (int i = 0; i < A.size(); i++){
            if(A[i] >= 0){
                lhs = i - 1;
                rhs = i + 1;
                res[index++] = A[i]*A[i];
                break;
            }
        }
        while(lhs >= 0 && rhs < A.size()){
            if(abs(A[lhs]) <= A[rhs]){
                res[index++] = A[lhs] * A[lhs];
                --lhs;
            } else {
                res[index++] = A[rhs] * A[rhs];
                ++rhs;
            }
        }
        cout << lhs << " " << rhs << endl;
        if(lhs < 0){
            for (int i = rhs; i < A.size(); i++){
                res[index++] = A[i] * A[i];
            }
        } else {
            for (int i = lhs; i >= 0; i--){
                res[index++] = A[i] * A[i];
            }
        }
        return res; 
    }
}; */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) { // 巧妙的方法
        int n = A.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (abs(A[i]) > A[j]){
                ans[pos] = A[i] * A[i];
                ++i;
            }
            else {
                ans[pos] = A[j] * A[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {-1};
    auto res = sol.sortedSquares(vec);
    for(auto x : res){
        cout << x << " ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {    // 最蠢的双指针，搞个函数，加个flag，可以把两个循环变成一个
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int lhs = 0;
        int rhs = 1;
        
        int res1 = 1;   // 防止只有一个数的情况
        // step1:
        while(rhs < arr.size()) {
            if(rhs&1 && arr[rhs] > arr[rhs-1]){  // 奇数
                res1 = max(rhs - lhs + 1, res1);
                cout << lhs << " " << rhs << endl;
            } else if(rhs%2 == 0 && arr[rhs] < arr[rhs-1]){
                res1 = max(rhs - lhs + 1, res1);
                cout << lhs << " " << rhs << endl;
            } else {
                cout << " : " << lhs << " " << rhs << endl;
                lhs = rhs;
            }
            rhs++;
        }
        int res2 = 1;
        lhs = 0;
        rhs = 1;
        // step2:
        while(rhs < arr.size()) {
            if(rhs&1 && arr[rhs] < arr[rhs-1]){  // 奇数
                res1 = max(rhs - lhs + 1, res1);
                cout << lhs << " " << rhs << endl;
            } else if(rhs%2 == 0 && arr[rhs] > arr[rhs-1]){
                res1 = max(rhs - lhs + 1, res1);
                cout << lhs << " " << rhs << endl;
            } else {
                cout << " : " << lhs << " " << rhs << endl;
                lhs = rhs;
            }
            rhs++;
        }

        return max(res1, res2);
    }
};

int main(){
    Solution sol;
    vector<int> vec = {4,8,12,16};
    cout << sol.maxTurbulenceSize(vec) << endl;
    return 0;
}
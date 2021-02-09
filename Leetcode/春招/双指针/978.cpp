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

class Solution {    // 这样一次遍历就可以了，和上面的区别是这个只需要遍历一次
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ret = 1;
        int left = 0, right = 0;

        while (right < n - 1) {
            if (left == right) {
                if (arr[left] == arr[left + 1]) {
                    left++;
                }
                right++;
            } else {
                if (arr[right - 1] < arr[right] && arr[right] > arr[right + 1]) {
                    right++;
                } else if (arr[right - 1] > arr[right] && arr[right] < arr[right + 1]) {
                    right++;
                } else {
                    left = right;
                }
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {4,8,12,16};
    cout << sol.maxTurbulenceSize(vec) << endl;
    return 0;
}
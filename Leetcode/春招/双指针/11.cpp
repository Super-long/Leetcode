#include <bits/stdc++.h>
using namespace std;

// 非常常见的一道面试题，但是第一次见不太好证明
// 与单调栈不同的是本题求的是离得最远的下标而不是离得最近的下标
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lhs = 0;
        int rhs = height.size() - 1;
        int res = INT_MIN;
        while(lhs <= rhs){
            res = max(min(height[lhs], height[rhs]) * (rhs - lhs), res);
            // 相等的时候其实不太好推，我们可以想象如果两个下标相等只有一种情况会使得res再增加，就是区间内有两个更大的下标，如果有的话无论如何下标都会再收缩到那两个上的
            if(height[lhs] <= height[rhs]){ 
                lhs++;
            } else {
                rhs--;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,1};
    cout << sol.maxArea(vec) << endl;;
}
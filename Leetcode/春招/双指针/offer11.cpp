#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 思路完全是错误的
public:
    int minArray(vector<int>& numbers) {
        int lhs = 0;
        int rhs = numbers.size() - 1;
        int ans = numbers.size();
        while(lhs <= rhs){  // 找最高点
            int mid = lhs + (rhs - lhs)/2;
            if(numbers[mid] >= numbers[lhs]){
                ans = mid;
                lhs = mid + 1;
            } else {
                rhs = mid - 1;
            }
        }
        return ans == numbers.size() - 1 ? numbers[0] : numbers[ans];
    }
}; */

class Solution {
public: // https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-by-leetcode-s/
    int minArray(vector<int>& numbers) {    // 这题其实挺麻烦的，需要分析清楚三种情况，不然搞不出来的。题解还是比较清楚的。
        int lhs = 0;
        int rhs = numbers.size() - 1;
        while(lhs < rhs){
            int mid = lhs + (rhs - lhs)/2;
            if(numbers[mid] > numbers[rhs]){    // 左侧其实也可以比较
                lhs = mid + 1;
            } else if(numbers[mid] < numbers[rhs]){
                rhs = mid;
            } else {
                rhs--;
            }
        }
        return numbers[lhs];
    }
};
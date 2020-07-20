// 两数之和 II - 输入有序数组
#include <bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/
// 这道双指针法本质类似于杨氏矩阵
// 一般而言搜索空间都是一个靠右上的三角形（lhs <= rhs），当然这道题没有等于
// 然后随着两个指针的推移可以降低时间复杂度
// 这道题最大的收获就是知道了双指针法的本质

class Solution {    
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int index1 = 0;
        int index2 = numbers.size() - 1;
        while(true){
            int sum = numbers[index1] + numbers[index2];
            if(sum < target){
                index1++;
            }else if(sum > target){
                index2--;
            }else {
                break;  // 保证有解
            }
        }
        res.push_back(move(index1 + 1));
        res.push_back(move(index2 + 1));
        return res;
    }
};
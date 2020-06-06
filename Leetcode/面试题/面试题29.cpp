//顺时针打印矩阵
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return {};

        int row = matrix.size();
        int col  =matrix[0].size();
        vector<int> res;
        int left = 0, right = col - 1, top = 0, bottom = row - 1;
        while(left <= right && top <= bottom){
            for(int column = left; column <= right; ++column){
                res.push_back(matrix[top][column]);
            }
            for(int rows = top+1; rows <= bottom; ++rows){
                res.push_back(matrix[rows][right]);
            }
            if(left < right && top < bottom){ // 至少有一行可以遍历
                for(int column = right-1; column >= left; --column){
                    res.push_back(matrix[bottom][column]);
                }
                for(int rows = bottom; rows > top; --rows){
                    res.push_back(matrix[rows][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};
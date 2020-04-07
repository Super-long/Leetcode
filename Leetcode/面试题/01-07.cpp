// 翻转矩阵
#include <bits/stdc++.h>
using namespace std;

// matrix[row][col] = martix[col][n-row-1]
// 三种方法 
class Solution { //上下翻转,对角线翻转
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main(){

}
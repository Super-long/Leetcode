// 矩阵中的最长递增路径
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rows;
    int cols;
    static constexpr const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        rows = matrix.size();
        cols = matrix[0].size();
        auto res = vector<vector<int>> (rows, vector <int> (cols));
        int ans = 0;
        for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < cols; j++){
                ans = max(ans, dfs(matrix, i, j, res));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& res){
        if(res[row][col]) return res[row][col];
        ++res[row][col];
        for(size_t i = 0; i < 4; i++){
            int x = row + dirs[i][0];
            int y = col + dirs[i][1];
            if(x >=0 && x < rows && y >= 0 && y < cols && matrix[x][y] > matrix[row][col]){
                res[row][col] = max(res[row][col], dfs(matrix, x, y, res) + 1);
            }
        }
        return res[row][col];
    }
};
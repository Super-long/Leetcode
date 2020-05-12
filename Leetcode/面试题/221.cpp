// 最大正方形
#include <bits/stdc++.h>
using namespace std;

/* class Solution { //暴力
private:
vector<vector<char>>* val;

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        val = &matrix;
        int ral = matrix.size();
        int row = 0;
        if(ral)  row = matrix[0].size();
        int res = 0;
        for(size_t i = 0; i < ral; i++){
            for(size_t j = 0; j < row; j++){
                if(matrix[i][j] == 49){
                    res = max(res, span(i, j, ral, row));
                    //cout << i << " " << j << " " << res << endl;
                }   
            }
        }
        //cout << span(1,2,ral, row) << endl;
        return res;
    }
private:
    int span(int x, int y, int ral, int row){
        int sum = 0;
        for(size_t i = y; i < row; i++){
            if(istrue(i-y+x, i, x, y ,ral)){
                int s = i - y + 1; //正方形边长
                sum += (s*s)-(s-1)*(s-1);
            }else break;
        }
        return sum;
    }

    bool istrue(int x, int y, int xx, int yy, int ral){
        if(x >=  ral) return false;
        //cout << x << " " << y << endl;
        for(int i = yy;i <= y; i++)
            if((*val)[x][i] == 48) return false;
        
        for(int i = xx; i <= x; i++)
            if((*val)[i][y] == 48) return false;

        return true;
    }
};
 */

class Solution { //dp
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // 这个dp[i][j]的含义是以这个点为右下角的全1正方形的最大边长
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> vec = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','0','1'},
        {'1','0','1','1','1'}
    };
    cout << sol.maximalSquare(vec) << endl;
    return 0;
}
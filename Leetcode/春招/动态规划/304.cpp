#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> mp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        for (size_t i = 1; i <= row; i++){
            for (size_t j = 1; j <= col; j++){
                dp[i][j] += matrix[i-1][j-1] + dp[i][j-1];
            }
            for (size_t j = 1; j <= col; j++){
                dp[i][j] += dp[i-1][j];
            }
        }
        for(auto item : dp){
            for(auto x : item){
                cout << x << " ";
            }
            putchar('\n');
        }
        swap(dp, mp);
    }


    int sumRegion(int row1, int col1, int row2, int col2) {
        return mp[row2+1][col2+1] + mp[row1][col1] - mp[row2+1][col1] - mp[row1][col2+1];
    }
};
int main(){
    vector<vector<int>> vec = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix res(vec);
    /*
    sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
    */
    cout << res.sumRegion(2,1,4,3) << endl;
    cout << res.sumRegion(1,1,2,2) << endl;
    cout << res.sumRegion(1,2,2,4) << endl;
}
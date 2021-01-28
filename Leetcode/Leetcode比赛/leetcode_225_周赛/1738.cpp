#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void fill(vector<int>& row, int j, vector<vector<int>>& matrix){
        row[0] = matrix[j][0];
        for (size_t i = 1; i < row.size(); i++){
            row[i] = matrix[j][i] ^ row[i-1];
        }
    }
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> row_anwser(n);

        fill(row_anwser, 0, matrix);
        
        for (size_t i = 0; i < n; i++){
            cout << row_anwser[i] << " ";
            dp[0][i] = row_anwser[i];
        }
        putchar('\n');

        for (size_t i = 1; i < m; i++){
            fill(row_anwser, i, matrix);
            for (size_t j = 0; j < n; j++){
                dp[i][j] = row_anwser[j] ^ dp[i-1][j];
            }
        }
        
        for (size_t i = 0; i < m; i++){
            for (size_t j = 0; j < n; j++){
                que.push(dp[i][j]);
                if(que.size() == k + 1){
                    que.pop();
                }
            }
        }
        while(que.size() == 1){
            que.pop();
        }
        return que.top();
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec = {
        {5,2},
        {1,6}
    };
    cout << sol.kthLargestValue(vec, 3) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m));
        for (size_t i = 0; i < m; i++){
            if(matrix[0][i] == 0) {
                vis[0][i] = 0;
            } else {
                vis[0][i] = 1;
            }
        }
        
        for(int i = 0; i < m; i++) {    // 列
            for (int j = 1; j < n; j++) {   // 行
                if(matrix[j][i] == 0){
                    vis[j][i] = 0;
                } else {
                    vis[j][i] = vis[j-1][i] + 1;
                }
                
            }
        }

        for(int i = 0; i < n; i++) {    // 列
            for (int j = 0; j < m; j++) {   // 行
                cout << vis[i][j] << " ";
            }
            putchar('\n');
        }

        vector<int> res(m, 0);
        int result = INT_MIN; 
        for (size_t i = 0; i < n; i++){
            copy(vis[i].begin(), vis[i].end(), res.begin());
            sort(res.begin(), res.end());
            for (int j = 0; j < m; j++){
                result = max(result, res[j] * (m - j));
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> res = {
        {1,1,0},
        {1,0,1}
    };
    cout << sol.largestSubmatrix(res) << endl;
    return 0;
}
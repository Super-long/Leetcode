// 不同路径 II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(!n) return 0;
        int m = obstacleGrid[0].size();
        vector<int> res(m);
        res[0] = (obstacleGrid[0][0] == 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j]){
                    res[j] = 0;
                    continue;
                } 
                if(j - 1 >= 0){
                    res[j] += res[j - 1];
                }
            }
        }
        return res.back();
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << sol.uniquePathsWithObstacles(vec) << endl;
    return 0;
}
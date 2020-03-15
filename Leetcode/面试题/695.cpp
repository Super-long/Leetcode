//岛屿最大面积 最大联通块

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool vis[55][55];
    int x[4]={1,0,-1,0}; //右 上 左 下
    int y[4]={0,1,0,-1};
    int num = 0;
    int Max = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<grid.size();++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(grid[i][j]){
                    num = 1;
                    dfs(i, j, grid);
                    Max = max(Max, num);
                }
            }
        }
        return Max;
    }

    void dfs(int i, int j, vector<vector<int>>& grid){
        if(!vis[i][j]){
            vis[i][j] =1;
            for(int k=0;k<4;++k){
                int xx = i+x[k];
                int yy = j+y[k];
                if(xx>=0 && xx<grid.size() && yy>=0 && yy<grid[i].size() && grid[xx][yy] && !vis[xx][yy]){
                    ++num;
                    dfs(xx, yy, grid);
                }
            }
        }
    }
};

int main(){
/*     vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}}; */
    vector<vector<int>> grid = {{0,0,0,0,0,0,0,0}};
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
    return 0;
}
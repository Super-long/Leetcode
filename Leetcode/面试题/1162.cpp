#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int x[4] = {0,0,1,-1};
    int y[4] = {1,-1,0,0};
    int vis[105][105];
    bool flag[105][105];
public:
    int maxDistance(vector<vector<int>>& grid) {
        memset(vis, 300 ,sizeof vis);
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]){
                    memset(flag, 0, sizeof flag);
                    bfs(i, j, grid);
                }
            }
        }
        return result(grid);
    }

    int result(vector<vector<int>>& grid) const {
        int res = -1;
        int sumone=0,sumzero=0; 
        for(size_t i = 0; i < grid.size(); i++){
            for(size_t j = 0; j < grid[i].size(); j++){
                if(!grid[i][j]){
                    ++sumzero;
                    res = max(res, vis[i][j]);
                }else{
                    ++sumone;
                }
            }
        }
        return !sumone || !sumzero ? -1 : res;
    }

    void bfs(int lhs, int rhs,vector<vector<int>>& grid){
        queue<pair<pair<int, int>,int>> que;
        que.push(make_pair(make_pair(lhs, rhs),0));
        flag[lhs][rhs] = true;
        while(que.size()){
            auto entry = que.front();
            que.pop();
            for(size_t i = 0; i < 4; i++){
                int xx = entry.first.first + x[i];
                int yy = entry.first.second+ y[i];
                if(xx >=0 && xx<grid.size() && yy>=0 && yy<grid[lhs].size() && !flag[xx][yy] && !grid[xx][yy]){
                    vis[xx][yy] = min(vis[xx][yy], entry.second+1);
                    flag[xx][yy] = true;
                    que.push(make_pair(make_pair(xx, yy),entry.second+1));
                } 
            }
        }
    }
};

int main(){
    vector<vector<int>> vec = {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    Solution sol;
    cout << sol.maxDistance(vec) << endl;
    return 0;
}
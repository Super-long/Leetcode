#include <bits/stdc++.h>
using namespace std;

class Solution {    // 这题也可以用并查集解
private:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};

    // 在此条件下能否找到一条路
    bool bfs(vector<vector<int>>& heights, vector<int>& vis, int mid, int n, int m){
        using pa = pair<int, int>;
        queue<pa> que;
        que.push(make_pair(0,0));
        vis[0] = true;
        while(que.size()){
            auto node = que.front();
            que.pop();
            for (size_t i = 0; i < 4; i++){
                int xx = x[i] + node.first;
                int yy = y[i] + node.second;
                if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx*m + yy] && abs(heights[xx][yy] - heights[node.first][node.second]) <= mid){
                    cout << xx << ", " << yy << ", " << mid << endl;
                    que.push(make_pair(xx, yy));
                    vis[xx*m + yy] = true;
                }
            }
        }
        if(vis[m*n - 1]){
            return true;
        } else {
            return false;
        }
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lhs = 0;
        int rhs = 999999;
        int ans = 1000000;
        int m = heights.size();
        int n = heights[0].size();
        vector<int> vis(m*n, 0);
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(bfs(heights, vis, mid, m ,n)){
                ans = mid;
                rhs = mid - 1;
            } else {
                lhs = mid + 1;
            }
            fill(vis.begin(), vis.end(), 0);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    // [[1,2,3],[3,8,4],[5,3,5]
    // [1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]
    vector<vector<int>> res = {
/*         {1,2,1,1,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,1,1,2,1} */
        {1,10,6,7,9,10,4,9}
    };
    cout << sol.minimumEffortPath(res) << endl;
    return 0;
}
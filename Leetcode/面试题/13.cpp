// 机器人的运动范围
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool vis[105][105]; 
    int get(int x) {
        int res=0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if(!k) return 1;
        int res = 1;
        memset(vis, 0, sizeof vis);
        queue<pair<int,int>> que;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        que.push(make_pair(0,0));
        while(que.size()){
            auto item = que.front();
            que.pop();
            for(int i=0;i<2;++i){ // 优化的地方,因为正常bfs可能会回溯,而这道题在一个值满足条件的时候
                int xx = dx[i] + item.first;
                int yy = dy[i] + item.second;
                if(xx >= 0 && xx < m && yy >= 0 && yy < n && !vis[xx][yy] && get(xx)+get(yy) <= k){
                    vis[xx][yy] = 1;
                    que.push(make_pair(xx,yy));
                    ++res;
                }
            }
        } 
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.movingCount(3,1,0) << endl;
    return 0;
}

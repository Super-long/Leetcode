#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    vector<int> parent;
    int find(int node){
        if(node != parent[node]){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void Union(int lhs, int rhs){
        int x = find(lhs);
        int y = find(rhs);
        if(x != y){
            parent[x] = y;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for(auto x : connections){
            Union(x[0], x[1]);
        }
        unordered_map<int, int> vis;
        for(auto& x : parent){
            x = find(x);
            vis[x]++;
        }
        int num = vis.size();    // 记录连通块数量
        int res = 0;
        for(auto x : vis){
            res += x.second - 1;    // 连通块内节点数减一，为块内连接最小边数
            cout << x.second << endl;
        }
        if(connections.size() - res >= num - 1){
            return num - 1;
        } else {
            return -1;
        }
    }
};

//[0,1],[0,2],[0,3],[1,2],[1,3]
int main(){
    Solution sol;
    vector<vector<int>> vec = {
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {1,3}
    };
    cout << sol.makeConnected(6, vec) << endl;
    return 0;
}

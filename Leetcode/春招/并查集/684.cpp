#include <bits/stdc++.h>
using namespace std;

// 这道题的解法有很多，本质就是找到一个环，拓扑排序也可以解

class Solution {
private:
    int find(vector<int>& parent, int node){    // 路径压缩
        if(node != parent[node]){
            parent[node] = find(parent, parent[node]);
        }
        return parent[node];
    }

    void Union(vector<int>& parent, int node1, int node2){
        parent[find(parent, node1)] = find(parent, node2);  // 要保证整个集合与另一个集合合并
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        size_t len = edges.size();
        vector<int> parent(len + 1);
        for(size_t i = 1; i <= len; i++){
            parent[i] = i;
        }

        for (size_t i = 0; i < len; i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            if(find(parent, node1) != find(parent, node2)){
                Union(parent, node1, node2);
            } else {
                return edges[i];
            }
        }
        return vector<int>{};
    }
};
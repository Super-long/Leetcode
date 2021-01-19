#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct edge{
        int len;
        int x;
        int y;
        edge(int len, int x, int y) : x(x), y(y), len(len){}

        bool operator<(const edge& rhs) {
            return len < rhs.len;
        }
    };

    vector<int> parent;

    int find(int node){
        if(node != parent[node]){
            parent[node] = find(parent[node]); 
        }
        return parent[node];
    }

    bool Union(int lhs, int rhs){   // 判断是否处于一个集合
        int x = find(lhs);
        int y = find(rhs);
        if(x != y){
            parent[x] = y;
            return false;   // 不连通返回false
        }
        return true;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        parent.resize(points.size());
        for (size_t i = 0; i < points.size(); i++){
            parent[i] = i;
        }

        auto dist = [&](int x, int y) -> int {  // 这个x，y其实是下标
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };

        vector<edge> edges;
        int len = points.size();

        for (size_t i = 0; i < len; i++){
            for (size_t j = 0; j < len; j++){
                edges.emplace_back(dist(i, j), i, j);   
            }
        }
        
        sort(edges.begin(), edges.end());
        int res = 0;
        int sum = 0;

        for (size_t i = 0; i < edges.size(); i++){
            if(Union(edges[i].x, edges[i].y)){
                continue;
            }
            res += edges[i].len;
            sum++;
            if(sum == len) break;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    cout << sol.minCostConnectPoints(vec) << endl;
    return 0;
}
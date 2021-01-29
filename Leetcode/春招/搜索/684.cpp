#include <bits/stdc++.h>
using namespace std;

class Solution {    // 并查集和拓扑排序都可以解；当然深搜也可以
private:
    bool dfs(const vector<vector<int>>& graph, vector<bool>& vis, int node1, int node2){
        if(node1 == node2) return true;
        if(vis[node1]) return false;    // node1 != node2，且node1被标记了，直接就可以返回false了 

        vis[node1] = true;
        for(auto& x : graph[node1]){
            if(dfs(graph, vis, x, node2)) return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size() + 1;
        vector<vector<int>> graph(len);
        vector<bool> vis(len);       

        for(auto& x : edges){
            fill(vis.begin(), vis.end(), 0);
            if(dfs(graph, vis, x[0], x[1])){
                return {x[0], x[1]};    // 第一次成环说明这就是答案，因为只存在在一个环
            }
            graph[x[0]].push_back(x[1]);// 边搜索边建图
            graph[x[1]].push_back(x[0]);
        }

        return vector<int>{};
    }
};

/*
class Solution {    // 并查集和拓扑排序都可以解
private:
    bool dfs(const vector<vector<int>>& graph, vector<bool>& vis, int node1, int node2){
        if(node1 == node2) return true;
        for(auto& x : graph[node1]){
            if(!vis[x]){
                vis[x] = true;
                if(dfs(graph, vis, x, node2)) return true;
                vis[x] = false;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size() + 1;
        vector<vector<int>> graph(len);
        vector<bool> vis(len);       
        queue<int> que;

        for(auto& x : edges){
            fill(vis.begin(), vis.end(), 0);
            vis[x[0]] = true;
            if(dfs(graph, vis, x[0], x[1])){
                return {x[0], x[1]};    // 第一次成环说明这就是答案，因为只存在在一个环
            }
            graph[x[0]].push_back(x[1]);// 边搜索边建图
            graph[x[1]].push_back(x[0]);
        }

        return vector<int>{};
    }
};
*/

int main(){
    int temp = 0;
    function<bool(int)> fun = [&](int x) -> bool{   // 闭包想要递归必须让闭包对象本身出现在捕获列表中
        if(x == 100) return true;
        fun(x + 1);
        return false;
    };
    
    return 0;
}
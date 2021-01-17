#include <bits/stdc++.h>
using namespace std;

// 并查集也可以解，这里用拓扑排序解
class Solution {
private:
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>{}(p.first) + std::hash<int>{}(p.second);
    }
};
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        vector<vector<int>> graph(len);
        unordered_set<pair<int, int>, SimpleHash> se;
        vector<int> degree(len, 0);
        queue<int> que;

        for (size_t i = 0; i < len; i++){
            int first = edges[i][0] - 1;
            int second = edges[i][1] - 1;

            graph[first].push_back(second);
            graph[second].push_back(first);

            se.insert(std::make_pair(first, second));
            se.insert(std::make_pair(second, first));

            degree[first]++;
            degree[second]++;
        }
        

        for (size_t i = 0; i < len; i++){
            if(degree[i] == 1){
                que.push(i);
            }
        }

        while(que.size()){
            int node = que.front();
            que.pop();

            for(auto x : graph[node]){
                degree[x]--;
                se.erase(std::make_pair(node, x));
                se.erase(std::make_pair(x, node));
                if(degree[x] == 1){
                    que.push(x);
                }
            }
        }

        for (int i = len - 1; i >= 0; i--){
            if(se.find(make_pair(edges[i][0] - 1, edges[i][1] - 1)) != se.end()){
                return {edges[i][0], edges[i][1]};
            }
        }
        
        return {};
    }
};

int main(){
    Solution sol;

}
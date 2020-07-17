// 判断二分图 染色问题
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    static constexpr int UNCOLORED = 0;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(!graph.size()) return false;
        vector<int> color(graph[0].size(), 0);
        for(size_t i = 0; i < graph[0].size(); i++){
            if(color[i] == UNCOLORED){  // 防止出现多个不相连的图
                queue<int> que;
                que.push(i);
                color[i] = RED;
                while(que.size()){
                    int Top = que.front();
                    que.pop();
                    int neiExpectedColor = color[Top] == RED ? GREEN : RED;
                    for(int neighbor : graph[Top]){
                        if(color[neighbor] == UNCOLORED){
                            color[neighbor] = neiExpectedColor;
                            que.push(neighbor);
                        }else if(color[neighbor] != neiExpectedColor){
                            return false;
                        }
                    }
                    
                }
            }
        }
        return true;
    }
};


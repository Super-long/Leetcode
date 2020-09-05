#include <bits/stdc++.h>
using namespace std;

/* class Solution { // dfs
    vector<vector<int>> edges;
    vector<int> state;
    bool vaild = true;
    // 0未探索 1正在探索 2探索完成
public:
    void dfs(int node){
        state[node] = 1;
        for (int i = 0; i < edges[node].size(); i++){
            if(state[edges[node][i]] == 0){
                dfs(edges[node][i]);
                if(!vaild) return;
            }else if(state[edges[node][i]] == 1){ //碰上未探索完毕的则是形成环
                vaild = false;
                return;
            }
        }
        state[node] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        state.resize(numCourses);
        for(auto& item : prerequisites){
            edges[item[0]].push_back(item[1]);
        }

        for (int i = 0; i < numCourses; i++){
            if(!state[i]){
                dfs(i);
            }
            if(!vaild) return vaild;
        }
        return vaild;
    }
};
 */

class Solution {
    vector<vector<int>> edges;
    vector<int> agree;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        agree.resize(numCourses);
        for(auto& item : prerequisites){
            edges[item[0]].push_back(item[1]);
            agree[item[1]]++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(agree[i] == 0)
                que.push(i);
        }
        int visited = 0;
        while(que.size()){
            ++visited;
            int Top = que.front();
            que.pop();
            //cout << Top << endl;
            for (int i = 0; i < edges[Top].size(); i++){
                agree[edges[Top][i]]--;
                if(agree[edges[Top][i]] == 0){
                    que.push(edges[Top][i]);
                }
            }
        }
        return visited == numCourses;
    }
};
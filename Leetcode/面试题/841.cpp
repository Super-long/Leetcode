#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<bool> vis;
    int sum;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(!rooms.size()) return true;
        sum = 0;
        vis.resize(rooms.size());
        dfs(rooms, 0);
        return sum == rooms.size();
    }

    void dfs(vector<vector<int>>& rooms, int x){
        vis[x] = true;
        ++sum;
        for(auto item : rooms[x]){
            if(!vis[item]){
                dfs(rooms, item);
            }
        }
        return;
    }
};
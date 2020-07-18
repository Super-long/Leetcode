// 跳跃游戏 IV
#include <bits/stdc++.h>
using namespace std;

class Solution {    // 选择最后一个点为初始点非常巧妙，因为保证了每一步都是最优
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> vis(n, 0);
        vector<int> dis(n, INT_MAX);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n-1; i++){
            mp[arr[i]].push_back(i);
        }
        dis[n-1] = 0;
        vis[n-1] = 1;
        queue<int> que;
        que.push(n-1);
        while(que.size()){
            int top = que.front();
            que.pop();
            cout << top << endl;                //mp中找不到的时候说明与此值相同的点已经被遍历
            if(top - 1 >= 0 && !vis[top-1] && mp.find(arr[top-1]) != mp.end()){// 左跳
                dis[top-1] = min(dis[top-1], dis[top]+1);
                vis[top-1] = 1;
                que.push(top - 1);
            }
            if(top + 1 < n && !vis[top+1] && mp.find(arr[top+1]) != mp.end()){
                dis[top+1] = min(dis[top+1], dis[top]+1);
                vis[top+1] = 1;
                que.push(top + 1);
            }
            if(mp.find(arr[top]) != mp.end()){
                for(auto x : mp[arr[top]]){ // 与当前值相同的下标
                    if(!vis[x]){
                        vis[x] = 1;
                        dis[x] = min(dis[x], dis[top]+1);
                        que.push(x);
                    }
                }
                mp.erase(arr[top]); // 巧妙
            }
        }
        return dis[0];
    }
};

int main(){
    Solution sol;
    vector<int> vec = {100,-23,-23,404,100,23,23,23,3,404};
    cout << sol.minJumps(vec) << endl;
    return 0;
}
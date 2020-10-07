#include <bits/stdc++.h>
using namespace std;

// f为父亲，i为孩子，i有n个子孙，一共N个节点
// dp[i]相比于dp[f],N - n - 2个节点要加1，n个节点减一
// dp[i] = dp[f] + (N - n - 2) - n
// dp[i] = dp[f] + N - 2(n + 1)
class Solution {
private:
    array<int, 10000+5> dp;
    vector<vector<int>> mp;
    int num;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        num = N;
        mp.clear();
        mp.resize(N);
        dp.fill(0);
        for(auto& x : edges){
            mp[x[0]].push_back(x[1]);
        }
        // 寻找root
        set<int> vis;
        for (int i = 0; i < N; i++){
            vis.insert(i);
        }
        
        int root = 0;
        for(auto& item : mp){
            for(auto x : item){
                vis.erase(x);
            }
        }
        for(auto x : vis){ // 此时理论只有一个
            root = x;
        }

        // 求dp[root]
        dp[root] = dfs1(root, mp);

        // 求每一项
        for(auto x : mp[root]){
            dfs2(root, x);
        }

        vector<int> res;
        for (int i = 0; i < N; i++){
            res.push_back(dp[i]);
        }
        return res;
    }

    int dfs1(int root, vector<vector<int>>& mp){
        if(mp[root].size() == 0) return 1;
        int res = 0;
        for(auto x : mp[root]){
            res += dfs1(x, mp);
        }
        return res + mp[root].size() + 1;
    }

    void dfs2(int father, int me){
        if(mp[me].size() == 0) return;
        dp[me] = dp[father] + num -2*(mp[father].size() - 1);
        for(auto x : mp[me]){
            dfs2(me, x);
        }
        return;
    }
};

int main(){
    vector<vector<int>> edges;
    Solution sol;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({2,3});
    edges.push_back({2,4});
    edges.push_back({2,5});
    
    auto res = sol.sumOfDistancesInTree(6, edges);
    for(auto x : res){
        cout << x << " ";
    }
    putchar('\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// f为父亲，i为孩子，i有n个子孙，一共N个节点    // n应该是以此节点为子树全部的孩子
// dp[i]相比于dp[f],N - n - 2个节点要加1，n个节点减一
// dp[i] = dp[f] + (N - n - 2) - n
// dp[i] = dp[f] + N - 2(n + 1)
class Solution {
private:
    array<int, 10000+5> dp;
    vector<vector<int>> mp;
    vector<int> childs;
    int num;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        num = N;
        mp.clear();
        mp.resize(N);
        dp.fill(0);
        childs.resize(N);

        // 无向图，有一个恶心的例子[[2,0],[1,0]]
        for(auto& x : edges){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        // 寻找root
/*         set<int> vis;
        for (int i = 0; i < N; i++){
            vis.insert(i);
        }
        
        // 貌似root只可能是零
        int root = 0;
        for(auto& item : mp){
            for(auto x : item){
                vis.erase(x);
            }
        }
        for(auto x : vis){ // 此时理论只有一个
            root = x;
        } */

        // 求dp[root]
        dp[0] = dfs1(0, mp, -1).first;
        // cout << dp[root] << endl;

        // 求每一项
        for(auto x : mp[0]){
            dfs2(0, x);
        }

        vector<int> res;
        for (int i = 0; i < N; i++){
            res.push_back(dp[i]);
        }
        return res;
    }

    // 加father的原因是因为是无向图，我们需要去掉指向父亲的那一条线
    pair<int, int> dfs1(int root, vector<vector<int>>& mp, int father){
        //if(mp[root].size() == 0) return {0, 1}; 
        // {dp[root], 以root为根的子节点数}
        int res = 0;
        childs[root] = 0;
        for(auto x : mp[root]){
            if(x == father) continue;
            auto pa = dfs1(x, mp, root);
            res += (pa.first + pa.second);
            childs[root] += pa.second;
        }   
        return {res, childs[root] + 1};
    }

    void dfs2(int father, int me){
        // if(mp[me].size() == 0) return;
        dp[me] = dp[father] + num - 2*childs[me] - 2;
        for(auto x : mp[me]){
            if(father == x) continue;
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
    edges.push_back({3,6});

    auto res = sol.sumOfDistancesInTree(7, edges);
    for(auto x : res){
        cout << x << " ";
    }
    putchar('\n');
    return 0;
}
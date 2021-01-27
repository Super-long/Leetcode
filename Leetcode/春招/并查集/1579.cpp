#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    class UnionFind {
        private:
            vector<int> parent;
        public:
            explicit UnionFind(int len){
                parent.resize(len + 1);
                iota(parent.begin(), parent.end(), 0);
            }

            int find(int node){
                if(node != parent[node]){
                    parent[node] = find(parent[node]);
                }
                return parent[node];
            }

            bool Union(int lhs, int  rhs){
                int x = find(lhs);
                int y = find(rhs);
                if(x != y){
                    parent[x] = y;
                    return true;    // 不连通时返回true
                }
                return false;
            }

            bool check(){    // 判断并查集内的连通分量是否为1
            cout << "strat\n";
                unordered_set<int> se;
                for (size_t i = 1; i < parent.size(); i++){
                    parent[i] = find(parent[i]);
                    se.insert(parent[i]);
                    cout << i << " " << parent[i] << endl;
                }
                cout << "size : " << se.size() << endl;
                return se.size() == 1;
            }
    };
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufAlice(n), ufBob(n);
        int res = 0;
        for (size_t i = 0; i < edges.size(); i++){
            if(edges[i][0] == 3){   // 第三类型优先级最高
                bool flag1 = ufAlice.Union(edges[i][1], edges[i][2]);
                bool flag2 = ufBob.Union(edges[i][1], edges[i][2]);
                if(!flag1 || !flag2){   // 有一个连通这条边就没意义，其实这两个flag位应该一直是一样的
                    res++;
                }
            }
        }

        for(size_t i = 0; i < edges.size(); i++){
            if(edges[i][0] == 1){
                if(!ufAlice.Union(edges[i][1], edges[i][2])){
                    cout << edges[i][1] << " " << edges[i][2] <<  " alice\n";
                    res++;
                }
            }

            if(edges[i][0] == 2){
                if(!ufBob.Union(edges[i][1], edges[i][2])){
                    cout <<edges[i][1] << " " << edges[i][2] <<  " bob\n";
                    res++;
                }
            }
        }
        
        if(ufAlice.check() && ufBob.check()) return res;
        return -1;  // 有一个人无法完全遍历
    }
};

int main(){
    Solution sol;//[[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
    vector<vector<int>> edges = {
        {3,1,2},
        {3,2,3},
        {1,1,3},
        {1,2,4},
        {1,1,2},
        {2,3,4}
    };
    cout << sol.maxNumEdgesToRemove(4, edges) << endl;
    return 0;
}
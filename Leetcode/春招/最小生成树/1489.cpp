#include <bits/stdc++.h>
using namespace std;

// 求最小生成树的关键边和伪边
class Solution {
private:
    class UnionFind{
        private:
            vector<int> parent;
            int NodeCount;  // 连通的边的个数
        public:
            explicit UnionFind(int n) : parent(n), NodeCount(0) {
                //iota(parent.begin(), parent.end(), 0)；   // 最小生成树的标准赋值方法
                for (size_t i = 0; i < n; i++){
                    parent[i] = i;
                }
            }

            int Find(int node){
                if(node != parent[node]){
                    parent[node] = Find(parent[node]);
                }
                return parent[node];
            }

            bool Union(int lhs, int rhs){
                int x = Find(parent[lhs]);
                int y = Find(parent[rhs]);
                if(x != y){ // 不连通
                    NodeCount++;
                    parent[x] =y;
                    return false;
                }
                return true;
            }

            int Count() const noexcept {
                return NodeCount;
            }
    };


public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int len = edges.size();

        for (size_t i = 0; i < len; i++){
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs){
            return lhs[2] < rhs[2];
        });

        int value = 0;  // 最小生成树的初始值
        UnionFind UF(n);
        for (size_t i = 0; i < len; i++){
            int lhs = edges[i][0];
            int rhs = edges[i][1];
            if(!UF.Union(lhs, rhs)){    // 倘若两个结点不连通的话
                value += edges[i][2];
            }
        }

        vector<vector<int>> res(2);     // 存放答案的集合

        for (size_t i = 0; i < len; i++){
            // 求关键边
            UnionFind UseForEffectiveEdge(n);
            int valueForEffectiveEdge = 0;
            for (size_t j = 0; j < len; j++){
                int lhs = edges[j][0];
                int rhs = edges[j][1];
                if(i != j && !UseForEffectiveEdge.Union(lhs, rhs)){
                    valueForEffectiveEdge += edges[j][2];
                }
            }

            // 不连通或者value变大
            if(UseForEffectiveEdge.Count() != n-1  || (UseForEffectiveEdge.Count() == n-1  && valueForEffectiveEdge > value)){
                res[0].push_back(edges[i][3]);
                continue;   // 已经是关键边则不需要下面判断
            }

            // 求非关键边
            UnionFind UseForNoneEffectiveEdge(n);
            UseForNoneEffectiveEdge.Union(edges[i][0],edges[i][1]); // 生成树包含这条边,且值与value相同证明是非关键边
            int valueForENoneffectiveEdge = edges[i][2];
            for (size_t j = 0; j < len; j++){
                int lhs = edges[j][0];
                int rhs = edges[j][1];
                if(i != j && !UseForNoneEffectiveEdge.Union(lhs, rhs)){
                    valueForENoneffectiveEdge += edges[j][2];
                }
            }
            // 连通且值等于
            if(UseForEffectiveEdge.Count() == n-1 && valueForENoneffectiveEdge == value){
                res[1].push_back(edges[i][3]);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec = {
/*     {0, 1, 1},
    {1, 2, 1},
    {2, 3, 2},
    {0, 3, 2},
    {0, 4, 3},
    {3, 4, 3},
    {1, 4, 6} */
    {0, 1, 1},
    {1, 2, 1},
    {0, 2, 1},
    {2, 3, 4},
    {3, 4, 2},
    {3, 5, 2},
    {4, 5, 2}
    };
    auto res = sol.findCriticalAndPseudoCriticalEdges(6, vec);
    for(auto x : res){
        for(auto t : x){
            cout << t << " ";
        }
        putchar('\n');
    }
    return 0;
}
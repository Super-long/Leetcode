#include <bits/stdc++.h>
using namespace std;

class Solution {    // 和1631几乎一样；二分也可以解，而且只需要在bfs中改一步就可以
private:
    class UnionFind{
        private:
            vector<int> parent;
            int find(int node){
                if(node != parent[node]){
                    parent[node] = find(parent[node]);
                }
                return parent[node];
            }
        public:
            explicit UnionFind(int len){
                parent.resize(len);
                iota(parent.begin(), parent.end(), 0);
            }

            void Union(int lhs, int rhs){
                if(!isUnion(lhs, rhs)){
                    parent[find(lhs)] = parent[find(rhs)];
                }
            }

            bool isUnion(int lhs, int rhs){
                int x = find(lhs);
                int y = find(rhs);
                if(x != y) return false;    // 不连通返回false
                return true;
            }
    };
public:
    int swimInWater(vector<vector<int>>& heights) {
        using edge = tuple<int, int, int>; 
        vector<edge> edges;

        int row = heights.size();
        int col = heights[0].size();
        for (int i = 1; i < col; i++){
            edges.push_back({abs(heights[0][i] - heights[0][i - 1]), i, i - 1});
        }
        for (int i = 1; i < row; i++){
            edges.push_back({abs(heights[i][0] - heights[i - 1][0]), i * col, (i-1)*col});
        }
        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                edges.push_back({abs(heights[i][j] - heights[i - 1][j]), i*col + j, (i-1)*col + j});
                edges.push_back({abs(heights[i][j] - heights[i][j - 1]), i*col + j, i*col + j - 1});
            }
        }

        auto check = [&heights, col](int x, int y) -> int{
            return max(heights[x/col][x%col], heights[y/col][y%col]);
        };
        sort(edges.begin(), edges.end(), [&](const edge& lhs, const edge& rhs) {    // 相比与1631，这里需要让结点值最大的边排在前面，因为使用的边的两头结点一定在路径上
            return check(std::get<1>(lhs), std::get<2>(lhs)) < check(std::get<1>(rhs), std::get<2>(rhs));
        });

        UnionFind uf(row*col);
        for(auto&[value, x, y] : edges){
            uf.Union(x, y);
            if(uf.isUnion(0, row*col - 1)){
                return max(heights[x/col][x%col], heights[y/col][y%col]);
            }
        }
        return 0; // 一个点的情况
    }
};

int main(){
    // [0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]
    Solution sol;
    vector<vector<int>> res = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6} 
        //{1,10,6,7,9,10,4,9}
    };
    cout << sol.swimInWater(res) << endl;
    return 0;
}
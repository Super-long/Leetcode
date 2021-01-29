#include <bits/stdc++.h>
using namespace std;

// 这题也可以用二分解
// 用并查集算是奇技淫巧，一般想不到，不过这启发我们用连通性去判断通路
class Solution {
private:
    struct edge{
        int value;
        int x,y;
        edge(int value, int x, int y) : value(value), x(x), y(y) {}
        bool operator > (const edge& param) const {
            return value > param.value;
        }
    };
/* 
    bool operator < (const edge& lhs, const edge& rhs){
        return lhs.value < rhs.value;
    } */

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
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<edge, vector<edge>, greater<edge>> que;  // 下次这种题可以用tuple表示结构
        int row = heights.size();
        int col = heights[0].size();
        for (int i = 1; i < col; i++){
            que.emplace(edge{abs(heights[0][i] - heights[0][i - 1]), i, i - 1});
        }
        for (int i = 1; i < row; i++){
            que.emplace(edge{abs(heights[i][0] - heights[i - 1][0]), i * col, (i-1)*col});
        }
        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                que.emplace(edge{abs(heights[i][j] - heights[i - 1][j]), i*col + j, (i-1)*col + j});
                que.emplace(edge{abs(heights[i][j] - heights[i][j - 1]), i*col + j, i*col + j - 1});
            }
        }
        UnionFind uf(row*col);
        while(que.size()){
            auto item = que.top();
            que.pop();
            uf.Union(item.x, item.y);
            if(uf.isUnion(0, row*col - 1)){ // 第一次连通证明上面那条边就是最小的那条关键边
                return item.value;
            }
        }
        
        return 0; // 一个点的情况
    }
};

int main(){
    Solution sol;
    // [[1,2,2],[3,8,2],[5,3,5]] 2
    // [[1,2,3],[3,8,4],[5,3,5] 1
    // [1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1] 0
    vector<vector<int>> res = {
/*         {1,2,1,1,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,1,1,2,1} */
        //{1,10,6,7,9,10,4,9}
        {3}
    };
    cout << sol.minimumEffortPath(res) << endl;
    return 0;
}
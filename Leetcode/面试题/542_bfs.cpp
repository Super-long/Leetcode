// 01 矩阵
#include <bits/stdc++.h>
using namespace std;

class Solution {
const int x[4] = {1,0,-1,0};
const int y[4] = {0,1,0,-1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> que;
        vector<vector<int>> res;
        res.resize(matrix.size());
        for(size_t i = 0; i < matrix.size(); i++){
            res[i].resize(matrix[i].size());
            for(size_t j = 0; j < matrix[i].size(); j++){
                if(!matrix[i][j]){
                    que.push(std::make_pair(i,j));
                    res[i][j] = -1;
                }
            }
        }
        while(que.size()){
            auto item = que.front();
            que.pop();
            for(int i = 0; i < 4; ++i){
                int xx = item.first + x[i];
                int yy = item.second + y[i];
                if(xx >= 0 && xx < matrix.size() && yy >= 0 && yy < matrix[0].size()){ //位置有效
                    if(!res[xx][yy]){
                        res[xx][yy] = (res[item.first][item.second] < 0 ? 0 : res[item.first][item.second]) + 1;
                        que.push(make_pair(xx,yy));
                    }
                }
            }
        }
    for(size_t i = 0; i < res.size(); i++){
        for(size_t j = 0; j < res[i].size(); j++){
            if(res[i][j] == -1) res[i][j] = 0;
        }
    }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    auto matrix = sol.updateMatrix(vec);
    for(size_t i = 0; i < matrix.size(); i++){
        for(size_t j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        putchar('\n');
    }
    return 0;
}
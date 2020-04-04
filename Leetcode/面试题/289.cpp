// 生命雨水 元胞自动机
#include <bits/stdc++.h>
using namespace std;

class Solution {
/**
 * -1 : 过去是活的,现在是死的
 *  1 : 过去是活的,现在是活的
 *  2 : 过去是死的,现在活的
 *  0 : 过去是死的
*/
private:
const int neighbors[3] = {0, 1, -1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(size_t i = 0; i < board.size(); i++){
            for(size_t j = 0; j < board[i].size(); j++){
                int livenumbers = 0;
                for(int k=0;k<3;++k){
                    for(int l=0;l<3;++l){
                        if(!neighbors[k] && !neighbors[l]) continue;
                        int xx = i+neighbors[k];
                        int yy = j+neighbors[l];
                        if(xx >= 0 && xx < board.size() && yy >= 0 && yy < board[i].size() && (board[xx][yy] == 1 || board[xx][yy] == -1)){
                            ++livenumbers;
                        }
                    }
                }
                if(board[i][j] == 1 && livenumbers != 2 && livenumbers !=3){
                    board[i][j] = -1;
                }else if(!board[i][j] && livenumbers == 3){
                    board[i][j] = 2;
                }
            }
        }
        for(size_t i = 0; i < board.size(); ++i){
            for(size_t j = 0; j < board[i].size(); ++j){
                if(board[i][j] <= 0){
                    board[i][j] = 0;
                }else{
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main(){
    vector<vector<int>> pool = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    Solution sol;
    sol.gameOfLife(pool);
    for(size_t i = 0; i < pool.size(); i++){
        for(size_t j = 0; j < pool[i].size(); j++){
            cout << pool[i][j] << " ";
        }
        putchar('\n');
    }
    return 0;
}
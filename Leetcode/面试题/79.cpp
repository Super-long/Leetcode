#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    int col;
    int row;
    bool OK;
    void dfs(int xp, int yp,int index, string& str, vector<vector<char>>& board, vector<vector<bool>>& vis){
        if(OK) return;
        if(index >= str.size()){
            OK = true;  // 找到答案
            return;
        }
        for (int i = 0; i < 4; i++){
            int xx = xp + x[i];
            int yy = yp + y[i];
            if(xx >= 0 && xx < row && yy >=0 && yy < col && !vis[xx][yy] && str[index] == board[xx][yy]){
                vis[xx][yy] = true;
                dfs(xx, yy, index+1, str,board, vis);
                vis[xx][yy] = false;
            }
        }
        return;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(200);
        for (int i = 0; i < 200; i++){
            vis[i].resize(200, false);
        }
        row = board.size();
        col = board[0].size();
        OK = false;

        for(size_t i = 0; i < row; i++){
            for(size_t j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = true;
                    dfs(i, j, 1, word, board, vis);
                    vis[i][j] = false;
                    if(OK) return true;
                }
            }
        }
        return false;
    }
};
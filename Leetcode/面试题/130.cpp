#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int x[4] = {0,1,-1,0};
    int y[4] = {1,0,0,-1};
    int col, row;
    void dfs(int xp, int yp, vector<vector<char>>& board){
        board[xp][yp] = 'A';    //　剪枝+得出答案
        for (int i = 0; i < 4; i++){
            int xx = xp + x[i];
            int yy = yp + y[i];
            if(xx >= 0 && xx < row && yy >= 0 && yy < col && board[xx][yy] == 'O'){
                dfs(xx, yy, board);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        col = board[0].size();
        row = board.size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if((i == 0 || i == row-1 || j == 0 || j == col-1) 
                    && board[i][j] == 'O'){
                    dfs(i, j, board);
                }
            }
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};


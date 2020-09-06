#include <bits/stdc++.h>
using namespace std;

class Solution {    // 原题第三步 很重要
private:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1}; 

    void dfs(int x, int y, vector<vector<char>>& board){
        int sum = 0;    // 这个位置的地雷数
        for (size_t i = 0; i < 8; i++){
            int xx = x + dir_x[i];
            int yy = y + dir_y[i];
            if(xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()){
                if(board[xx][yy] == 'M') ++sum;
            }
        }
        if(sum != 0){
            board[x][y] = sum + '0';
        }else {
            board[x][y] = 'B';
            for (size_t i = 0; i < 8; i++){
                int xx = x + dir_x[i];
                int yy = y + dir_y[i];
                if(xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && board[xx][yy] == 'E'){
                    dfs(xx, yy, board);
                }
            }   
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
        } else {
            dfs(click[0], click[1], board);
        }
        return board;
    }
};
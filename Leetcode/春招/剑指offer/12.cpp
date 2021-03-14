#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int row;
    int col;
    int xx[4] = {1,0,-1,0};
    int yy[4] = {0,1,0,-1};
    int flag = false;
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int index){
        if(flag) return true;
        cout << index << " " << word.size() << endl;
        if(index >= word.size()){
            return flag = true;
        }
        for (int i = 0; i < 4; i++){
            int m = xx[i] + x;
            int n = yy[i] + y;
            if(m >= row || m < 0 || n >= col || n < 0 || board[m][n] == '\0' || board[m][n] != word[index]) continue;
            board[m][n] = '\0';
            dfs(board, word, m, n, index + 1); 
            board[m][n] = word[index];
        }
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        if(!row || !word.size()) return true;
        col = board[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    board[i][j] = '\0';
                    if(dfs(board, word, i, j, 1)){
                         return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};
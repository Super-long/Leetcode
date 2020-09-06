#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        if (image[x][y] == color) {
            image[x][y] = newColor;
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < image.size() && my >= 0 && my < image[0].size()) {
                    dfs(image, mx, my, color, newColor);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor = image[sr][sc];
        if (currColor != newColor) {
            dfs(image, sr, sc, currColor, newColor);
        }
        return image;
    }
};

int main(){
    vector<vector<int>> vec = {
        {1,1,1},
        {1,1,0},
        {1,0,1},
    };

    Solution sol;
    auto res = sol.floodFill(vec, 1, 1, 2);
    for (size_t i = 0; i < res.size(); i++){
        for (size_t j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        putchar('\n');
    }
    return 0;
}
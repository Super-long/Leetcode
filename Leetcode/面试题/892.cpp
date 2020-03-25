//三维形体的表面积
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i=0; i<grid.size();++i){
            for(int j=0; j<grid[i].size();++j){
                int level = grid[i][j];
                if(!level) continue;
                sum += level*4+2;
                sum -= i>0 ? min(level, grid[i-1][j])*2 : 0;
                sum -= j>0 ? min(level, grid[i][j-1])*2 : 0;
            }
        }
        return sum;
    }
};
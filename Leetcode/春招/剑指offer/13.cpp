#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int target;
    int res = 1;
    int target_m;
    int target_n;
    vector<vector<int>> mp; 
    static int exchange(int para){
        int sum = 0;
        while(para){
            sum += (para%10);
            para /= 10;
        }
        return sum;
    }

    int xx[4] = {0,0,1,-1};
    int yy[4] = {1,-1,0,0};

    void dfs(int x, int y){
        for (size_t i = 0; i < 4; i++){
            int m = x + xx[i];
            int n = y + yy[i];
            if(m < 0 || m >= target_m || n < 0 || n >= target_n || exchange(m) + exchange(n) > target || mp[m][n]) continue;
            mp[m][n] = 1;
            res++;
            dfs(m, n);
        }
        
    }
public:
    int movingCount(int m, int n, int k) {
        mp.resize(m, vector<int>(n, 0));
        target_m = m;
        target_n = n;
        target = k;
        mp[0][0] = 1;
        dfs(0,0);
        return res;
    }
};
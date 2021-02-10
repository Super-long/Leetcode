#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    bool check(const vector<vector<int>>& mp, int mid, int threshold){
        for (size_t i = mid; i < mp.size(); i++){
            for (size_t j = mid; j < mp[0].size(); j++){
                cout << i << " " << j << " " << mid << endl;
                if(mp[i][j] - mp[i][j-mid] - mp[i-mid][j] + mp[i-mid][j-mid] <= threshold){
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size() + 1;
        int col = mat[0].size() + 1;

        vector<vector<int>> mp(row, vector<int>(col, 0));
        
        for (size_t i = 1; i < row; i++){
            for (size_t j = 1; j < col; j++){
                mp[i][j] = mp[i-1][j] + mp[i][j-1] + mat[i-1][j-1] - mp[i-1][j-1];
                cout << mp[i][j] << " ";
            }
            putchar('\n');
        }

        int lhs = 1;
        int rhs = min(row, col) - 1;
        int ans = rhs + 1;
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(check(mp, mid, threshold)){
                ans = mid;
                lhs = mid + 1;
                cout << mid << "shang\n";
            } else {
                cout << mid << "xia\n";
                rhs = mid - 1;
            }
        }
        return ans == min(row, col) ? 0 : ans;  // 完全可能没找到答案
    }
};

int main(){
    Solution sol;//[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]
    vector<vector<int>> vec = {
        {2,2,2,2,2},
        {2,2,2,2,2},
        {2,2,2,2,2},
        {2,2,2,2,2},
        {2,2,2,2,2}
    };
    cout << sol.maxSideLength(vec, 1) << endl;
    return 0; 
}
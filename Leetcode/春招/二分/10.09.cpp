#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(!row) return false;
        int col = matrix[0].size();
        int lhs = 0;
        int rhs = col - 1;
        for(int i = row - 1; i >= 0; i--){
            int ans = col;
            cout << lhs << " " << rhs << endl;
            while(lhs <= rhs){
                int mid = lhs +(rhs - lhs)/2;
                if(matrix[i][mid] >= target){
                    ans = mid;
                    rhs = mid - 1;
                } else {
                    lhs = mid + 1;
                }
            }
            if(ans == col){ return false; }//右边界已经出去了，不可能了
            if(matrix[i][ans] == target) return true;
            cout << ans << endl;
            lhs = ans;
            rhs = col - 1;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> vec = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution sol;
    cout << sol.searchMatrix(vec, 20) << endl;
    return 0;
}
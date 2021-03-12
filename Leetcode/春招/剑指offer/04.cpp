#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(!row) return 0;
        int col = matrix[0].size();
        int lhs = 0;
        int rhs = col - 1;
        int ans = col;
        int index = -1;
        for (int i = row - 1; i >= 0; i--){
            while(lhs <= rhs){
                int mid = lhs + (rhs - lhs)/2;
                if(matrix[i][mid] >= target){
                    ans = mid;
                    rhs = mid - 1;
                } else {
                    lhs = mid + 1;
                }
            }
            if(ans == col) return false;
            if(matrix[i][ans] == target) return true;
            cout << ans << endl;
            if(ans == col - 1){
                index = i;
                break;
            }
            lhs = ans;
            rhs = col - 1;
            ans = col;
        }
        for(int i = index; i >= 0; --i){
            if(matrix[i][col - 1] == target){
                return true;
            }
        }
        return false;
    }
};
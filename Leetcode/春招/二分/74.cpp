#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int len = matrix[0].size();
        int lhs = 0;
        int rhs = len * matrix.size() - 1;
        int ans = rhs + 1;

        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            cout << ans << endl;
            int row = mid / len;
            int col = mid % len;
            cout << mid <<" " <<row << " " << col << endl;
            if(matrix[row][col] >= target){
                rhs = mid - 1;
                ans = mid;
            } else {
                lhs = mid + 1;
            }
        }
        
        int row = ans / len;
        int col = ans % len;
        cout << ans << " " << row << " " << col << endl;
        if(ans == len * matrix.size() || matrix[row][col] != target){    // 没找到且大于最后一个值
            return false;
        } else {
            return true;
        }
    }
};

int main(){//[1,3,5,7],[10,11,16,20],[23,30,34,60]
    Solution sol;
    vector<vector<int>> vec = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    cout << sol.searchMatrix(vec, 34) << endl;
    return 0;
}
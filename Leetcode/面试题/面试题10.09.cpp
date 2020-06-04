//排序矩阵查找
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 过了运气好，时间复杂度最差是nlogn，只不过logn中n的常数会随数据不同而下降，
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();
        int row = 0, col = m;
        while(true){
            vector<int>::iterator itera = lower_bound(matrix[row].begin(), matrix[row].begin()+col, target);
            cout << *itera << endl;
            if(itera != matrix[row].end() && *itera == target){
                return true;
            }
            col = distance(matrix[row].begin(), itera);
            cout << col << endl;
            ++row;
            if(row == n) break;
        }
        return false;
    }
}; */

class Solution { // logn*logn
public:
    //思路：某个元素左边都是比自己小的元素，元素下边都是比自己大的元素，
    //那么可以选择第一行最后一个元素作为比较的起始点。
    //该元素 == ，return； 该元素 > target, 列号-1； 该元素 < target,行号+1

    bool searchMatrix(vector<vector<int>>& matrix, int iRow, int iColumn, int target)
    {
        if (iRow == matrix.size() - 1)			//到达最后一行
        {
            if (matrix[iRow][iColumn] < target)
            {
                return false;
            }
        }
        if (iColumn == 0)
        {
            if (matrix[iRow][iColumn] > target)
            {
                return false;
            }
        }

        if (matrix[iRow][iColumn] == target)
        {
            return true;
        }
        else if (matrix[iRow][iColumn] > target)
        {
            return searchMatrix(matrix, iRow, iColumn - 1, target);
        }
        else
        {
            return searchMatrix(matrix, iRow + 1, iColumn, target);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        return searchMatrix(matrix, 0, matrix[0].size() - 1, target);
    }
};



int main(){
    Solution sol;
    vector<vector<int>> vec = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout << sol.searchMatrix(vec, 20) << endl;
    return 0;
}
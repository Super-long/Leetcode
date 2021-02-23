#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> prev = matrix[0];
        for (size_t i = 1; i < row; i++){
            vector<int>& item = matrix[i]; 
            for (size_t j = 1; j < col; j++){
                if(item[j] != prev[j - 1]){
                    return false;
                }
            }
            prev = item;
        }
        return true;
    }
};
// 如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？
// 也不难，我们需要把矩阵划分为几个子矩阵，记录最后一个元素就可以了

int main(){
    Solution sol;

    vector<vector<int>> res = {
        {1,2,3,4},
        {5,1,2,3},
        {9,5,1,2}
    };
    cout << sol.isToeplitzMatrix(res) << endl;
    return 0;
}
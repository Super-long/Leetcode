// 最大全1矩阵
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int maxsum = 0;
        vector<int> dp(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                dp[j] = matrix[i][j] == '1' ? dp[j]+1 : 0; // 太巧妙了
            }
            maxsum = max(maxsum, largestRectangleArea(dp));
        }
        return maxsum;
    }

    int largestRectangleArea(vector<int> heights) { // 84的代码
        int MaxArea = 0;
        vector<int> sta;
        heights.insert(heights.begin(), 0); 
        heights.push_back(0);
        for(int i = 0;i < heights.size(); ++i){
            while(!sta.empty() && heights[sta.back()] > heights[i]){
                int Top = sta.back();
                sta.pop_back();
                int left = sta.back() + 1;
                int right = i - 1;
                MaxArea = max(MaxArea, (right - left + 1)*heights[Top]);
            }
            sta.push_back(i);
        }
        return MaxArea;
    }
};
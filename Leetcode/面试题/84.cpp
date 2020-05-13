// 柱状图中最大的矩形
#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { // 暴力超时
        int MaxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int minHeight = INT_MAX;
            for(int j = i; j < heights.size(); j++){
                minHeight = min(minHeight,heights[j]);
                MaxArea = max(MaxArea, minHeight*(j-i+1));
            }
        }
        return MaxArea;
    }
}; */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { // 单调栈
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


int main(){
    vector<int> vec = {2,1,5,6,2,3};
    Solution sol;
    cout << sol.largestRectangleArea(vec) << endl;
    return 0;
}
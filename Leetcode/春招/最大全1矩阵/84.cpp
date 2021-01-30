#include <bits/stdc++.h>
using namespace std;

class Solution {    // 柱状图中最大矩形；暴力or单调栈
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> res; // 存储每一个值的左右区间
        res.resize(heights.size());
        stack<int> stkl;
        for (size_t i = 0; i < heights.size(); i++){
            while(!stkl.empty()){
                if(heights[stkl.top()] >= heights[i]){
                    stkl.pop();
                } else {
                    break;
                }
            }   // 此时栈中的值全部小于heighs[i]
            if(stkl.empty()){    // 说明左区间全部的值都大于当前下标的值，左区间定位0
                res[i].first = 0;
            } else {
                res[i].first = stkl.top() + 1;  //
            }
            stkl.push(i);
        }

        stack<int> stkr;
        for (int i = heights.size() - 1; i >= 0; i--){
            while(!stkr.empty()){
                if(heights[stkr.top()] > heights[i]){
                    stkr.pop();
                } else {
                    break;
                }
            }
            if(stkr.empty()){
                res[i].second = heights.size() - 1;
            } else {
                res[i].second = stkr.top() - 1;  //
            }
            stkr.push(i);
        }
        
        int result = INT_MIN;
        for(int i = 0; i < heights.size(); ++i){
            int lhs, rhs;
            tie(lhs, rhs) = res[i];
            cout << lhs << " " << rhs << endl;
            result = max(result, heights[i]*(rhs - lhs + 1));
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(vec) << endl;
    return 0;
}
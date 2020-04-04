// 接雨水
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> sta;
        int current = 0;
        int sum = 0;
        while(current < height.size()){
            while(!sta.empty() && height[current] > height[sta.top()]){
                int Top = sta.top();
                sta.pop();
                if(sta.empty()) break;
                int length = current - sta.top()-1;
                int value = min(height[current], height[sta.top()]) - height[Top];
                sum += value*length;
            }
            sta.push(current++);
        } 
        return sum;
    }
};
// 暴力N2也可 不想写了

int main(){
    Solution sol;
    vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(vec) << endl;
    return 0;
}
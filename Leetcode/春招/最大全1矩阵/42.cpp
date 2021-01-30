#include <bits/stdc++.h>
using namespace std;

/* class Solution {    // 写暴毙了；思路是求每一个值的左右区间
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> res; // 存储每一个值的左右区间
        int len = height.size();
        res.resize(len);
        stack<int> stkl;

        for (size_t i = 0; i < len; i++){
            while(!stkl.empty()){
                if(stkl.top() <= height[i]){
                    stkl.pop();
                } else {
                    break;
                }
            }   // 保证栈中的值严格大于当前值

            if(stkl.empty()){
                res[i].first = i;
            } else {
                res[i].first = stkl.top();
            }
            stkl.push(height[i]);
        }

        stkl = stack<int>();
        for (int i = len - 1; i >= 0; i--){
            while(!stkl.empty()){
                if(stkl.top() <= height[i]){
                    stkl.pop();
                } else {
                    break;
                }
            }   // 保证栈中的值严格大于当前值
            if(stkl.empty()){
                res[i].second = i;
            } else {
                res[i].second = stkl.top();
            }
            stkl.push(height[i]);
        }

        int result = 0;
        for(size_t i = 0; i < len; i++){
            auto& item = res[i];
            cout << i << " " <<item.first << " " << item.second << endl;
            bool flag = item.first == i || item.second == i;
            result += flag ? 0 : (abs(height[item.second] - height[item.first]) - height[i]) * (item.second - item.first - 1);
        }
        return result;
    }
}; */

class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(vec) << endl;
    return 0;
}
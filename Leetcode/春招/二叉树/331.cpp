#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        auto check = [](const string& pre, int index) -> int {
            int count = 0;
            while(pre[index] >= '0' && pre[index] <= '9') {
                count++;
                index++;
            }
            return count;
        };
        stack<int> stk;
        int len = preorder.length();
        int index = 0;
        stk.push(1);
        while(stk.size() && index < len){
            if(preorder[index] == ','){
                index++;
                continue;
            }
            auto temp = stk.top();
            stk.pop();
            if(temp == 2){
                stk.push(1);
            } 
            if(preorder[index] != '#'){
                stk.push(2);
                index += check(preorder, index);
                continue;
            }
            index++;
        }
        return stk.size() || index < len ? false : true;
    }
};
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 双指针
public:
    bool backspaceCompare(string S, string T) {
        bool flag = true;
        int lhs = S.size() - 1;
        int rhs = T.size() - 1;
        int lSize = 0;
        int rSize = 0;
        while(lhs >= 0 || rhs >= 0){
            while(lhs >= 0){
                if(S[lhs] == '#'){
                    lhs--;
                    lSize++;
                } else if(lSize != 0){
                    lhs--;
                    lSize--;
                } else {    // 找到一个可比较的数字
                    break;
                }
            }
            while(rhs >= 0){
                if(T[rhs] == '#'){
                    rhs--;
                    rSize++;
                } else if(rSize != 0){
                    rhs--;
                    rSize--;
                } else {
                    break;
                }
            }
            if(lhs >= 0 && rhs >= 0){
                if(S[lhs] != T[rhs]){
                    flag = false;
                    break;
                }
                lhs--;
                rhs--;
            } else if(lhs >= 0 || rhs >= 0){  // 其中一个可比，另一个不可比，证明错误
                flag = false;
                break;
            }
        }
        return flag;
    }
}; */

class Solution {    // 栈
public:
    bool backspaceCompare(string S, string T) {
        stack<int> StaS;
        stack<int> StaT;
        int number = 0;

        int StaLength = S.size() - 1;
        while (StaLength >= 0){
            if(S[StaLength] == '#'){
                number++;
            } else if(S[StaLength] != '#' && number){
                number--;
            } else {
                StaS.push(S[StaLength]);
            }
            StaLength--;
        }   

        number = 0;
        StaLength = T.size() - 1;
        while (StaLength >= 0){
            if(T[StaLength] == '#'){
                number++;
            } else if(T[StaLength] != '#' && number){
                number--;
            } else {
                StaT.push(T[StaLength]);
            }
            StaLength--;
        }
        cout << StaS.size() << " " <<  StaT.size() << endl;
        if(StaS.size() != StaT.size()) return false;
        while(StaS.size()){
            auto s = StaS.top();
            StaS.pop();
            auto t = StaT.top();
            StaT.pop();
            if(s != t) return false; 
        }   
        return true;
    }
};
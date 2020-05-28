// 字符串解码
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }
    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }
public:
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;
        while(ptr < s.size()){
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++])); 
            } else { // 右括号
                ptr++;
                vector<string> sub;
                while(stk.back() != "["){
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                stk.pop_back();
                int repTime = stoi(stk.back()); // 得到数字
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o; 
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};

int main(){
    Solution sol;
    string str = "3[a2[c]]";
    cout << sol.decodeString(str) << endl;
    return 0;
}
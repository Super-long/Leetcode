#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> res;
    void dfs(string s, int depth, int index, string now){
        if(depth >= 4){ // 最多允许四项
            if(index == s.size()){
                res.push_back(now);
            }
            return;
        }
        if(index >= s.size()) return;   // 有可能深度不到4的时候index超标

        if(depth != 0) now += '.';
        for (size_t i = 0; i < 3; i++){ // 每一项最多三个值
            if(i == 0 && s[index] == '0'){  // 不允许存在前导零
                dfs(s, depth + 1, index + 1, now + '0');
                break;  // 出现前导零后面的答案就没意义了
            }
            auto temp = s.substr(index, i + 1);
            if(stoi(temp) > 255) continue;  // 最大为255
            dfs(s, depth + 1, index + i + 1, now + temp);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
};

int main(){
    Solution sol;
    auto item = sol.restoreIpAddresses("1111");
    for(auto x : item) cout << x << endl;
    return 0;
}
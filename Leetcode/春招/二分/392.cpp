#include <bits/stdc++.h>
using namespace std; 

// 题目的进阶是当s的数量超过10亿（一个数组，大小十亿）的时候如何优化；
// https://github.com/labuladong/fucking-algorithm/blob/master/%E9%AB%98%E9%A2%91%E9%9D%A2%E8%AF%95%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E5%88%A4%E5%AE%9A%E5%AD%90%E5%BA%8F%E5%88%97.md
// 可以预处理t，对t做二分，时间复杂度可以到达MlogN，M为s数组的数量，N为t的长度
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.size()) return true;
        int index = 0;
        char ch = s[0];
        for(auto x : t){
            if(x == ch){
                index++;    // 已成功匹配的字符数
                if(index >= s.size()) break;
                ch = s[index];
            }
        }
        if(index >= s.size()) return true;
        return false;  
    }
};

int main(){
    Solution sol;
    cout << sol.isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}
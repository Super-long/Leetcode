// 判断子序列
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for(size_t i = 0; i < t.size(); i++){
            if(s[index] == t[i]){
                index++;
            }
        }
        if(index == s.size()) return true;
        return false;
    }
};
/*
bool isSubsequence(char * s, char * t){
    // if(*s == NULL){
    //     return true;
    // }else if(*t == NULL){
    //     return false;
    // }else{
    //     return (*s == *t? isSubsequence(s+1,t+1):isSubsequence(s,t+1));
    // }
}
*/

int main(){
    Solution sol;
    cout << sol.isSubsequence("axc", "ahbgdc") << endl;
    return 0;
}
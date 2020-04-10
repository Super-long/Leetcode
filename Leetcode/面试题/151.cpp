// 翻转字符串里的单词
#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    string reverseWords(string s) {
        if(!s.size()) return string();
        reverse(s.begin(), s.end());
        int index = 0;
        for(size_t i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                if(index) s[index++]=' ';
                int end = i;
                while(s[end]!=' ' && end < s.size()) s[index++]=s[end++];
                reverse(s.begin()+index-(end-i), s.begin()+index);
                cout << index << " " << i << " " << end << endl; 
                i = end;
            }
        }
        s.erase(s.begin()+index, s.end());
        return s;
    }
}; */

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res;
        vector<string> pool;
        while(ss >> res) pool.push_back(res);
        res.clear();
        for (int i = pool.size() - 1; i >= 0; i--) res+=pool[i] + " ";
        return res.size() ? string(res.begin() ,res.end()-1) : "";
    }
}; 

int main(){
    Solution sol;
    string str = {"a good   example"};
    cout << sol.reverseWords(str) << endl;
    return 0;
}
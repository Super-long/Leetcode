//单词的压缩编码
#include <bits/stdc++.h>
using namespace std;

class Solution {
static bool compare(string& s1, string& s2) {
    int N1 = s1.length();
    int N2 = s2.length();
    for (int i = 0; i < min(N1, N2); i++) {
        char c1 = s1[N1-1-i];
        char c2 = s2[N2-1-i];
        if (c1 != c2) {
            return c1 < c2;
        }
    }
    return N1 < N2;
}
bool endsWith(string& s, string& t) {
    int N1 = s.length();
    int N2 = t.length();
    if (N1 < N2) {
        return false;
    }
    for (int i = 0; i < N2; i++) {
        if (s[N1-N2+i] != t[i]) {
            return false;
        }
    }
    return true;
}

public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int res = 0;
        for(size_t i = 0; i < words.size(); i++){
            if(i+1 < words.size() && endsWith(words[i+1], words[i])){

            }else{
                res += words[i].size() +1;
            }
        }
        return res;
    }
};

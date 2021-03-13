#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for(auto x : s){
            count++;
        }
        int index = s.size() - 1;
        s.resize(s.size() + count * 2); 
        for(int i = 0; i < s.size(); i--){
            if(s[i] == ' '){
                s[index] = '0';
                s[index - 1] = '2';
                s[index - 2] = '%';
                index -= 3;
            } else {
                s[index] = s[i];
                index--;
            }
        }
        return s;
    }
};
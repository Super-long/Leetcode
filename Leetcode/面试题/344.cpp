#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int lhs = 0;
        int rhs = s.size();
        while(lhs <= rhs){
            swap(s[lhs++], s[rhs--]);
        }
        return;
    }
};
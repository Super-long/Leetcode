// “气球” 的最大数量
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int letter[26];
        memset(letter, 0, sizeof letter);
        for(auto ch : text){
            letter[ch-'a']++;
        }
        int Min = 0x3f3f3f3f;
        Min = min(Min, letter['b'-'a']);
        Min = min(Min, letter['a'-'a']);
        Min = min(Min, letter['n'-'a']);
        Min = min(Min, letter['o'-'a']/2);
        Min = min(Min, letter['l'-'a']/2);
        return Min;
    }
};


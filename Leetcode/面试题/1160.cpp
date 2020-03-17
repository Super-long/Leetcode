#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        std:;unordered_map<char, int> map;
        for(auto item : chars){
            map[item]++;
        }
        int sum = 0;
        for(auto& item : words){
            auto Temp = map;
            bool flag = false;
            for(auto x : item){
                if(Temp[x]){
                    flag =true;
                    break;
                }
                Temp[x]--;
            }
            if(!flag) sum+=item.size();
        }
        return sum;
    }
};


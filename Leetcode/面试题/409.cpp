#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> vec;
        for(auto x : s){
            vec[x]++; //没必要用map 数组就不错 还是O(1)
        }
        int sum = 0;
        int flag = 0;
        for(auto x : vec){
            if(x.second%2==0)
                sum+=x.second;
            else{
                sum+=x.second;
                flag++;
            }
        }
        if(flag>1) return sum-flag+1;
        else return sum;
    }
};

/**
 * 需要注意的样例
 * "ccc"
 * "aaaccc"
*/
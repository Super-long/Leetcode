#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int len = s.size();
        bool flag = false;  // true -; false +
        int res = 0;
        while(s[index] == ' ') index++;;
        if(index >= len) return 0;
        if(s[index] == '-') flag = true;
        if(s[index] == '-' || s[index] == '+') index++;

        while(index < len && s[index] >= '0' && s[index] <= '9'){
            int temp = s[index] - '0';
            if(flag){
                temp = -temp;
            }
            if(INT_MAX/10 < res || (INT_MAX/10 == res && temp > 7)) return INT_MAX;
            if(INT_MIN/10 > res || (INT_MIN/10 == res && temp < -8)) return INT_MIN;
            res = res * 10 + temp;
            index++;
        }
        return res;
    }
};
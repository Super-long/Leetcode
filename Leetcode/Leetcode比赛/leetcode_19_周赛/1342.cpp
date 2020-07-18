// 将数字变成 0 的操作次数
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while(num == 0){
            if(num%2 == 0){
                num /= 2;
            }else {
                num -= 1;
            }
            res ++;
        }
        return res;
    }
};
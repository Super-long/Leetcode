// 十进制整数的反码
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int num) {
        if(num == 0) return 1;
        int res = 0;
        int cnt = 0;
        int j = 0;
        while (num != 0){
            cnt =  num & 0x1;   // cnt为0的话是1， cnt是1的话为0
            res = res +  (1-cnt) * pow(2, j++);
            num >>= 1;
        }
        return res;
    }
};
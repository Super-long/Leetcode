#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n){
            if(n&1) sum++;
            n>>=1;
        }
        return sum;
    }
};
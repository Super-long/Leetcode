#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int rand10() {
        int temp1 = rand7();
        int temp2 = rand7();
        int ans = 7*(temp1 - 1) + temp2;
        if(ans > 40){
            return rand10();
        } else {
            return (ans % 10 )+ 1;
        }
    }
};
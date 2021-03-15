#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int one = 1;
        int two = 1;
        if(n <= 2) return 1;
        for (int i = 2; i < n; i++){
            int temp = (one + two)%1000000007;
            one = two;
            two = temp;
        }
        return two;
    }
};
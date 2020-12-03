#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c){   // 少考虑了一种情况{1, 3, 5}，就是真是脑经急转弯啊
        vector<int> vec{a,b,c};
        sort(vec.begin(), vec.end());
        a = vec[0];
        b = vec[1];
        c = vec[2];
        
        int interalA = b - a;
        int interalB = c - b;
        
        vector<int> res;
        int sumMIN = 0;   
        int sumMAX = 0;
        if(interalA > 1){
            sumMAX += interalA - 1;
            sumMIN += 1; 
        }

        if(interalB > 1){
            sumMAX += interalB - 1;
            sumMIN += 1; 
        }
        if(b - a == 2 || c - b == 2) sumMIN = 1;
        return vector<int>{sumMIN, sumMAX};
    }
};
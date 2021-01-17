#include <bits/stdc++.h>
using namespace std;

class Solution {    // 经典的简单题目
public:
    int uniquePaths(int m, int n) {
        vector<int> vecRes;
        vecRes.resize(n, 1);
        for (size_t i = 1; i < m; i++){
            for (size_t j = 1; j < n; j++){
                vecRes[j] = vecRes[j-1] + vecRes[j];
            }
            for (size_t k = 0; k < n; k++){
                cout << vecRes[k] << " ";
            }
            putchar('\n');
            
        }
        return vecRes.back();
    }
};
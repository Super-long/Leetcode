// 不同的二叉搜索树
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 1;
        for(size_t i = 2; i <= n; i++){
            for(size_t j = 1; j <= i; j++){  // 枚举中间点
                res[i] += res[j-1]*res[i-j];   
            }
        }
        return res[n];
    }
};
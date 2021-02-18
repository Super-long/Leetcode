#include <bits/stdc++.h>
using namespace std;

class Solution {    // 差分和滑动窗口都可以解
public:
    int minKBitFlips(vector<int>& A, int K) {//https://blog.csdn.net/qq_36025591/article/details/110311658
        vector<int> vis(A.size() + 1);
        int ans = 0;
        for (int i = 0, cnt = 0; i < A.size(); i++){
            cnt += vis[i];  // 前缀和
            if((A[i] + cnt) % 2 == 0){
                if (i + K > A.size()) return -1;
                vis[i + 1]++;
                vis[i + K]--;
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K)
    {
        int n = A.size();
        int result = 0;
        queue<int> que;

        for (int i = 0; i < n; ++i) {
            if (!que.empty() && i >= que.front() + K) {
                que.pop();
            }
            if (que.size() % 2 == A[i]) {
                if (i + K > n) {
                    return -1;
                }

                que.push(i);
                result += 1;
            }
        }
        return result;
    }
};
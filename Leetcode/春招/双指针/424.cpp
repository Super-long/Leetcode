#include <bits/stdc++.h>
using namespace std;

class Solution {    // 这题比较有意思
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        int lhs = 0;
        int rhs = 0;
        unordered_map<char, int> vis;   // AABABBA -- 1 -- 4
        int num = 0;    // 所有字符中出现的最大次数
        int result = 0;
        while(rhs < len) {
            char temp = s[rhs];
            vis[temp]++;
            if(vis[temp] > num){
                num = vis[temp];
            }
            if(rhs - lhs + 1 - num <= k){   // 因为num最大的时候才需要更新，后面可能会减小，但是不需要更新；
                result = rhs - lhs + 1; // 这里的答案只会递增，不需要max
            } else {
                auto item = s[lhs];
                vis[item]--;
                lhs++;
            }
            rhs++;
        }
        return result;
    }
};

class Solutions {   // 标准答案，
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;

        while (right < n) {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k) {
                num[s[left] - 'A']--;
                left++; // 感觉这里有问题，因为maxn还是没有同步修改；最大为maxn都无法有答案，加入的值不大于maxn也不可能有答案，而加入的值如果更新了maxn，则可能有正确答案；巧妙的避开了更新maxn
            }
            right++;
        }
        return right - left;
    }
}; 
// 最长连续序列
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:// 和我想法一样,不过我给写崩了 
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for (const int& num : nums) {
            mp.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : mp) {
            if (!mp.count(num - 1)) { // 这里把时间复杂度降到了O(N),挺巧妙的
                int currentNum = num;
                int currentStreak = 1;

                while (mp.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};


int main(){
    Solution sol;
    vector<int> vec = {100,4,200,1,3,2};
    cout << sol.longestConsecutive(vec) << endl;
    return 0;
}
// 寻找重复数
#include <bits/stdc++.h>
using namespace std;

// 这个题很有意思 但是有点不好想,如何把这个数组抽象成一个图
// 出现环肯定是 val[2,3] index[3,2],然后其他一个值与其中一个索引相同, 比如index为1 val为2或者3
class Solution { 
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(fast != slow);

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
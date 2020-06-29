// 数组中的第K个最大元素
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        int index = 0;

        
        while(index != nums.size()){
            que.push(nums[index]);
            if(que.size() == k + 1){
                que.pop();
            }
            ++index;
            //cout << que.top() << endl;
        }
        return que.top();
    }
};

int main(){
    Solution sol;
    vector<int> vec = {3,2,1,5,6,4};
    cout << sol.findKthLargest(vec, 2) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> que;
    int len;
public:
    KthLargest(int k, vector<int>& nums) {
        len = k;
        for (size_t i = 0; i < nums.size(); i++){
            que.push(nums[i]);
        }
        while(que.size() > k){
            que.pop();
        }
    }
    
    int add(int val) {
        que.push(val);
        while(que.size() > len){
            que.pop();
        }
        return que.top();
    }
};

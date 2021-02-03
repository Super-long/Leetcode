#include <bits/stdc++.h>
using namespace std;

class Solution {    // 一道比较难的模拟题，涉及到一个延时删除的策略，挺有意思的
private:
    priority_queue<double, vector<double>, greater<double>> hi;
    priority_queue<double, vector<double>, less<double>> lo;
    unordered_map<int, int> vis;
    int smallsize = 0,largesize = 0;

    void add(int sum){  // add和makeBlance是更标准的双堆写法；这题如果限定数字范围比较小的话还可以用计数排序来做
        if(!lo.size() || sum <= lo.top()){
            smallsize++;
            lo.push(sum);
        } else {
            largesize++;
            hi.push(sum);
        }
        makeBlance();
    }

    double findMedian() const {
        if(smallsize == largesize) return (lo.top() + hi.top()) / 2;
        else return lo.top();
    }

    void erase(int sum){
        vis[sum]++;
        if(sum <= lo.top()){
            smallsize--;
            if(sum == lo.top()){
                prune(lo);
            }
        } else {
            largesize--;
            if(sum == hi.top()){
                prune(hi);
            }
        }
        makeBlance();
    }

    void makeBlance(){
        //while(true){
            if(smallsize > largesize + 1){
                hi.push(lo.top());
                lo.pop();
                --smallsize;
                ++largesize;
                prune(lo);
            } else if(largesize > smallsize) {
                lo.push(hi.top());
                hi.pop();
                ++smallsize;
                --largesize;
                prune(hi);
            } /* else {
                prune(lo);
                prune(hi);
                break;  // 因为hi.top一定不是需要延时删除的值
            }
        } */
        // 到这里以后即平衡，顶部又不需要删除
    }

    template<typename heapType>
    void prune(heapType& heap){
        while(heap.size()){
            if(vis.find(heap.top()) != vis.end()){
                vis[heap.top()]--;
                if(vis[heap.top()] == 0) vis.erase(heap.top());
                heap.pop();
            } else {
                break;
            }
        }   // 堆顶元素不需要延时删除
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (size_t i = 0; i < k; i++){
            add(nums[i]);
        }
        res.push_back(findMedian());
        for (size_t i = k; i < nums.size(); i++){
            add(nums[i]);
            erase(nums[i - k]);
            res.push_back(findMedian());
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
    auto item = sol.medianSlidingWindow(vec, 3);
    for(auto x : item) cout << x << endl;
    return 0;
}
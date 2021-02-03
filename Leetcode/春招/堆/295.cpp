#include <bits/stdc++.h>
using namespace std;

/* class MedianFinder {
private:
    priority_queue<double, vector<double>, greater<double>> hi;
    priority_queue<double, vector<double>, less<double>> lo;
    int len;
public:
    MedianFinder() : len(0) {}
    
    void addNum(int num) {
        len++;
        lo.push(num);
    }
    
    double findMedian() {
        int rhs = len / 2;
        int lhs = len - rhs;
        while(lo.size() > lhs){
            hi.push(lo.top());
            lo.pop();
        }
        if(lhs == rhs){
            return (lo.top() + hi.top()) / 2;
        } else {
            return lo.top();
        }
    }
}; */

class MedianFinder {
private:
    priority_queue<double, vector<double>, greater<double>> hi;
    priority_queue<double, vector<double>, less<double>> lo;
    int len;
public:
    MedianFinder() : len(0) {}
    
    void addNum(int num) {
        len++;
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        while(hi.size() > lo.size()){
            lo.push(hi.top());
            hi.pop();
        }
        // 保证两个堆中始终存在着最大和最小的N个值;且lo长度始终大于hi
    }
    
    double findMedian() {
        int rhs = len / 2;
        int lhs = len - rhs;
        if(lhs == rhs){
            return (lo.top() + hi.top()) / 2;
        } else {
            return lo.top();
        }
    }
};
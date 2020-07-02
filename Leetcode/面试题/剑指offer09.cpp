// 两个栈实现一个队列
#include <bits/stdc++.h>
using namespace std;

class CQueue {
private:
stack<int> s1;
stack<int> s2;
int size;
public:
    CQueue() {
        size = 0;
    }
    
    void appendTail(int value) {
        s1.push(value);
        size++;
    }
    
    int deleteHead() {
        while(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!size) return -1;
        size--;
        int res = s2.top();
        s2.pop();
        return res; 
    }
};
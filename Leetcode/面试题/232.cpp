#include <bits/stdc++.h>
using namespace std;

class MyQueue{
private:
    stack<int> stkinput;
    stack<int> stkoutput;
    int len;
    void moveElement(){
        while(stkinput.size()){
            stkoutput.push(stkinput.top());
            stkinput.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() : len(0) {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stkinput.push(x);
        len++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stkoutput.empty()) {
            moveElement();
        }
        auto res = stkoutput.top();
        stkoutput.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(stkoutput.empty()) {
            moveElement();
        }
        return stkoutput.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !len;
    }
};
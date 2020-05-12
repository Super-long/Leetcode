// 最小栈
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> primary;
    stack<int> backup;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        primary.push(x);
        if(!backup.size() || x <= backup.top()){
            backup.push(x);
        }
    }
    
    void pop() {
        if(primary.top() == backup.top()){
            backup.pop();
        }
        primary.pop();
    }
    
    int top() {
        return primary.top();
    }
    
    int getMin() {
        return backup.top();
    }
};

/*
class MinStack { // 这样的写法也比较巧妙
    stack<int> s;
    int min;
public:
    MinStack() {

    }
    
    void push(int x) {
        if(s.empty()){
            min=x;
        }
        else if(min>=x){
            s.push(min);
            min=x;
        }
        s.push(x);
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        else if(s.size()==1){
            min=s.top();
        }
        else if(s.top()==min){
            s.pop();
            min=s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};
*/

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;   //--> 返回 -3.
    minStack.pop();
    cout << minStack.top() << endl;      //--> 返回 0.
    cout << minStack.getMin() << endl;   //--> 返回 -2.
    return 0;
}
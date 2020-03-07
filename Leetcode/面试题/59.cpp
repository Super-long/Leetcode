#include <bits/stdc++.h>
using namespace std;


class MaxQueue {
private:
std::queue<int> high;
std::deque<int> low;
int max;
public:
    MaxQueue() : max(-1){

    }
    
    int max_value() {
        if(!low.size()){
            return -1;
        }else{
            return low.front();
        }
    }
    
    void push_back(int value) {
        high.push(value);
        while(1){
            if(low.size() && value > low.back()){
                low.pop_back();
            }else{
                low.push_back(value);
                break;
            }
        }
    }
    
    int pop_front() {
        if(!high.size()) return -1;
        int temp = high.front();
        high.pop();
        if(temp == low.front()) {
            low.pop_front();
        }
        return temp;
    }
};

int main(){
    MaxQueue que;
    que.push_back(5);
    que.push_back(4);
    cout << que.max_value() << endl;
    que.pop_front();
    cout << que.max_value() << endl;
    return 0;
}
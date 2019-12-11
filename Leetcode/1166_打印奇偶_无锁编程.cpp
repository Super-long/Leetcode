#include<bits/stdc++.h>
using namespace std;

class ZeroEvenOdd {
private:
    enum class State { ZERO_ODD, ZERO_EVEN, ODD, EVEN };
    int n;
    int idx;
    std::atomic<State> st;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        idx = 1;
        st.store(State::ZERO_ODD, std::memory_order_seq_cst);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;){
            State Temp;
            if((Temp = st.load(std::memory_order_seq_cst)) == State::ZERO_ODD){
                printNumber(0);
                st.store(State::ODD, std::memory_order_seq_cst);
                ++i;
            }else if(st == State::ZERO_EVEN){
                printNumber(0);
                st.store(State::EVEN, std::memory_order_seq_cst);
                ++i;
            }
            std::this_thread::yield();
        }
    }

    void even(function<void(int)> printNumber) {
        while(idx <= n){
            if(st.load(std::memory_order_seq_cst) == State::EVEN){
                printNumber(idx++);
                st.store(State::ZERO_ODD, std::memory_order_seq_cst);
            }
            std::this_thread::yield();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(idx <= n){
            if(st.load(std::memory_order_seq_cst) == State::ODD){
                printNumber(idx++);
                st.store(State::ZERO_EVEN, std::memory_order_seq_cst);
            }
            std::this_thread::yield();
        }
    }
};
//这样在线程多了以后就可能导致线程调度一直到不了正确的线程 时间效率可能较大
//且使用不同的内存序效率差了近一半 这就很可怕了

int main(){
    ZeroEvenOdd temp(10);
    std::thread Zero(&ZeroEvenOdd::zero, &temp,[](int para){cout << para;});
    Zero.detach();
    std::thread Lockodd(&ZeroEvenOdd::odd, &temp,[](int para){cout << para;});
    Lockodd.detach();
    std::thread Lockeven(&ZeroEvenOdd::even, &temp,[](int para){cout << para;});
    Lockeven.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return 0;
}
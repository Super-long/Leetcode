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
        while(idx <= n){//感觉这里的操作类似于自旋锁
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

//使用memory_order_seq_cst:
//任何使用该选项的写操作都相当于release操作，任何读操作都相当于acquire操作
//memory_order_relaxed:
//这个选项如同其名字，比较松散，它仅仅只保证其成员函数操作本身是原子不可分割的，但是对于顺序性不做任何保证
//也就是说如果代码之间依赖性不高可以使用relaxed 否则则用合适的内存序使得代码不发生问题


//这样在线程多了以后就可能导致线程调度一直到不了正确的线程 时间效率可能较大
//且使用不同的内存序效率差了近一半 这就很可怕了
//(猜测 memory_order_relaxed可能使得指令重排 使yield在前面执行)

//两种情况效率均低于条件变量
//我认为在保护变量互斥的时候原子操作很好 可以减少锁的操作 从而减少时间 
//但是线程同步就有点慢了 可能是我写的有问题

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
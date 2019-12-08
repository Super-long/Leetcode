#include<bits/stdc++.h>
using namespace std;

//这样写这个题耗时很长 用了太多的锁

class ZeroEvenOdd {
private:
    int n;
    std::mutex lockzero;
    std::mutex lockodd;
    std::mutex lockeven;
public:
    ZeroEvenOdd(int n) : lockzero(), lockodd(), lockeven() {
        this->n = n;
        lockodd.lock();
        lockeven.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1; i <= n; ++i){
            lockzero.lock();
            printNumber(0);
            if(i&1) lockodd.unlock();
            else lockeven.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i+=2){
            lockeven.lock();
            printNumber(i);
            lockzero.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i+=2){
            lockodd.lock();
            printNumber(i);
            lockzero.unlock();
        }    
    }
};

int main(){
/*     int n = 0;
    cin >> n; */
    ZeroEvenOdd temp(10);
    //using std::placeholders::_1;
    
    //bind不能匹配 这是为什么呢
    
/*     std::thread Zero(std::bind(&ZeroEvenOdd::zero,temp,_1),[](int para){cout << para;});
    Zero.detach();
    std::thread Lockeven(std::bind(&ZeroEvenOdd::even,temp,_1),[](int para){cout << para;});
    Lockeven.detach();
    std::thread Lockodd(std::bind(&ZeroEvenOdd::odd,temp,_1),[](int para){cout << para;});
    Lockodd.detach(); */
    std::thread Zero(&ZeroEvenOdd::zero, &temp,[](int para){cout << para;});
    Zero.detach();
    std::thread Lockodd(&ZeroEvenOdd::odd, &temp,[](int para){cout << para;});
    Lockodd.detach();
    std::thread Lockeven(&ZeroEvenOdd::even, &temp,[](int para){cout << para;});
    Lockeven.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    std::condition_variable g_cv;
    std::mutex mt;
    bool ze,other;
public:
    ZeroEvenOdd(int n) : g_cv(), mt(), ze(false), other(true){
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i = 1; i <= n/2; ++i){
            cout << "i : " << i << endl;
            while(ze){
                std::unique_lock<std::mutex> lk(mt);
                //cout << "zero \n";
                g_cv.wait(lk, [=](){return ze;});
            }
            cout << i << " zero ";
            printNumber(0); cout << endl;
            ze = true;
            g_cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i+=2){
            while(!(ze && !other)){
                std::unique_lock<std::mutex> lk(mt);
                cout << "even\n";
                g_cv.wait(lk,[=](){return !(ze && !other);});
            }
            cout << i << " even ";
            printNumber(i); cout << endl;
            ze = false;
            other = true;
            g_cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i < n; i+=2){
            while(!(ze && other)){
                std::unique_lock<std::mutex> lk(mt);
                cout <<" odd\n";
                g_cv.wait(lk, [=](){return !(ze && other);});
            }
            cout <<i<< " odd ";
            printNumber(i); cout << endl;
            other = false;
            g_cv.notify_all();
        }
    }
};

//有问题 输出不规则 条件变量理解出现错误 逻辑大概对
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
//这样写错误的原因是因为不确定在发出条件变量后even odd两个线程谁先竞争到锁
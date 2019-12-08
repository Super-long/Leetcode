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
        for(int i = 1; i <= n; ++i){
            cout << "i : " << i << endl;
            while(ze){
                std::unique_lock<std::mutex> lk(mt);
                g_cv.wait(lk);
                cout << " zero\n";
            }
            printNumber(0);
            ze = true;
            g_cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i+=2){
            while(!(ze && !other)){
                std::unique_lock<std::mutex> lk(mt);
                g_cv.wait(lk);
            }
            printNumber(i);
            ze = false;
            other = true;
            g_cv.notify_all();
            cout << " even\n";
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i+=2){
            while(!(ze && other)){
                std::unique_lock<std::mutex> lk(mt);
                g_cv.wait(lk);
                cout << " odd\n";
            }
            printNumber(i);
            other = false;
            g_cv.notify_all();
        }
    }
};


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
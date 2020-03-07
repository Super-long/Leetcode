#include <bits/stdc++.h>

using namespace std;

class H2O {
private:
int Count;
std::mutex mh,mo;
    
public:
    H2O() : Count(0) {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        //std::lock_guard<std::mutex> guard(mutex_);
        mh.lock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++Count;
        if(Count >= 2){
            Count = 0;
            mo.unlock();
        }else{
            mh.unlock();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        mo.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if(Count == 2){
            Count = 0;
        }
        mh.unlock();
    }
};

void showH(){
    cout << "H";
}

void showO(){
    cout << "O";
}


int main(){
    string str;
    cin >> str;
    H2O h2o;
    auto num = str.size() / 3;
    //while(num--){ 
        std::thread ox(&H2O::oxygen, &h2o,showO);
        std::thread hy1(&H2O::hydrogen, &h2o, showH);
        std::thread hy2(&H2O::hydrogen, &h2o, showH);

        ox.join();
        hy1.join();
        hy2.join();
    //}
    return 0;
}

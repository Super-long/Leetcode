#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

class H2O {
private:
int count_H = 0;
sem_t h_limit;
sem_t o_limit;
    
public:
    H2O() {
        sem_init(&h_limit, 0, 2);
        sem_init(&o_limit, 0, 1);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h_limit);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        ++count_H;
        if(count_H == 2){
            count_H = 0;
            //sem_post(&o_limit);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o_limit);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
/*         sem_post(&h_limit);
        sem_post(&h_limit);   */  
    }
};

void showH(){
    cout << "H";
}

void showO(){
    cout << "O";
}

//这道其实写的有问题,去掉注释才能过,系统怎么控制输出多少的?

int main(){
    string str;
    cin >> str;
    H2O h2o;
    auto num = str.size() / 3;
    while(num--){ 
        std::thread ox(&H2O::oxygen, h2o,showO);
        std::thread hy1(&H2O::hydrogen, h2o, showH);
        std::thread hy2(&H2O::hydrogen, h2o, showH);

        ox.join();
        hy1.join();
        hy2.join();
    }
    return 0;
}
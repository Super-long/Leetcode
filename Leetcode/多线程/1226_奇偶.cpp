// 哲学家吃饭
#include <bits/stdc++.h>
using namespace std;

class DiningPhilosophers { // 分奇偶 只
private:
    std::mutex mutexs[5];
    void eating(function<void()> pickLeftFork,
                function<void()> pickRightFork,
                function<void()> eat,
                function<void()> putLeftFork,
                function<void()> putRightFork){
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
                    }
public:
    DiningPhilosophers() {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int lhs = philosopher;
        int rhs = (philosopher+1)%5;

		if(philosopher&1){ //奇数
            std::lock_guard<std::mutex> lock1(mutexs[lhs]);
            std::lock_guard<std::mutex> lock2(mutexs[rhs]);
            eating(pickLeftFork,pickRightFork, eat, putLeftFork, putRightFork);
        }else {
            std::lock_guard<std::mutex> lock2(mutexs[rhs]);
            std::lock_guard<std::mutex> lock1(mutexs[lhs]);
            eating(pickLeftFork,pickRightFork, eat, putLeftFork, putRightFork);
        }
    }
};
// 哲学家吃饭
#include <bits/stdc++.h>
using namespace std;

class DiningPhilosophers {
private:
    std::mutex mutexs[5];
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

        std::lock(mutexs[lhs], mutexs[rhs]);
        std::lock_guard<std::mutex> lock_a(mutexs[lhs], std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(mutexs[rhs], std::adopt_lock);
        
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork(); //在临界区内，其实左边右边顺序无关紧要
    }
};
// 哲学家吃饭
#include <bits/stdc++.h>
using namespace std;

#include <semaphore.h>

class DiningPhilosophers {
private:
    sem_t sem;
    std::mutex mutexs[5];
public:
    DiningPhilosophers() {
        sem_init(&sem, 0, 4); // 初始化信号量
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int lhs = philosopher;
        int rhs = (philosopher+1)%5;

        sem_wait(&sem);
        {
            std::lock_guard<std::mutex> lock1(mutexs[lhs]);
            std::lock_guard<std::mutex> lock2(mutexs[rhs]);

            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
        }
        sem_post(&sem);
    }
};
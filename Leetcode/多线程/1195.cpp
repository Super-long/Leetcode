#include <bits/stdc++.h>
using namespace std;

class FizzBuzz {
private:
    int n;
    std::atomic_int init;
    std::condition_variable cv;
    std::mutex mt;
public:
    FizzBuzz(int n) : init(1) {
        this->n = n;
        cv.notify_all();
    }

    // printFizz() outputs "fizz".3
    void fizz(function<void()> printFizz) {
        while(1){
            if(init > n) break;
            std::unique_lock<std::mutex> guard(mt);
            cv.wait(guard, [&]{if(init%3==0 && init%5 || init>n) return true; return false;});
            if(init > n) break;
            printFizz();
            ++init;
            cv.notify_all();
        }
        
    }

    // printBuzz() outputs "buzz".5
    void buzz(function<void()> printBuzz) {
        while(1){
            if(init > n) break;
            std::unique_lock<std::mutex> guard(mt);
            cv.wait(guard, [&]{if(init%5==0 && init%3 || init>n) return true; return false;});
            if(init > n) break;
            printBuzz();
            ++init;
            cv.notify_all();
        }  
    }

    // printFizzBuzz() outputs "fizzbuzz". 15
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(1){
            if(init > n) break;
            std::unique_lock<std::mutex> guard(mt);
            cv.wait(guard, [&]{if(init%15==0 || init>n) return true; return false;});
            if(init > n) break;
            printFizzBuzz();
            ++init;
            cv.notify_all();
        }  
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(1){
            if(init > n) break;
            std::unique_lock<std::mutex> guard(mt);
            cv.wait(guard, [&]{if(init%3 && init%5 || init>n) return true; return false;});
            if(init > n) break;
            printNumber(init);
            ++init;
            cv.notify_all();
        }  
    }
};

void showfizz(){
    std::cout << "fizz";
}

void showbuzz(){
    std::cout << "buzz";
}

void showfizzbuzz(){
    std::cout << "fizzbuzz";
}

void shownumber(int n){
    cout << n;
}

int main(){
    int n = 0;
    cin >> n;
    FizzBuzz FB(n);
    std::thread one(&FizzBuzz::fizz, &FB, showfizz);
    std::thread two(&FizzBuzz::buzz, &FB, showbuzz);
    std::thread three(&FizzBuzz::fizzbuzz, &FB, showfizzbuzz);
    std::thread four(&FizzBuzz::number, &FB, shownumber);    
    one.join(); two.join(); three.join(); four.join();
    return 0;
}
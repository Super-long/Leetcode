#include<bits/stdc++.h>
using namespace std;

class FooBar{
private:
    int n;
    std::atomic<bool> flag;
public:
    FooBar(int n): flag(true) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while(!flag.load(std::memory_order_acquire));
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag.store(false, std::memory_order_release);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while(flag.load(std::memory_order_acquire));
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag.store(true, std::memory_order_release);
        }
    }
};

void printone(){
    cout << "foo";
}

void printtwo(){
    cout << "bar";
}

int main(){
    int n;
    cin >> n;
    FooBar T(n);
    std::thread one(&FooBar::foo, &T, printone);
    std::thread two(&FooBar::bar, &T, printtwo);
    one.join();
    two.join();
    return 0;
}
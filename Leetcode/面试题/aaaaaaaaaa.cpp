#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec = {1,2,30};
    vector<int> res;
    res = std::move(vec);
    for(auto x : res){
        cout << x  << " ";
    }
    putchar('\n');
    cout << vec.size() << endl;
    return 0;
}
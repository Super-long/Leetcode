#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> items = {1,2,3};
    int index = upper_bound(items.begin(), items.end(), 2) - items.begin();
    cout << index << endl;
    return 0;
}
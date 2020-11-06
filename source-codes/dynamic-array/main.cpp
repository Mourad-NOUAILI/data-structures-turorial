#include "dynamic_array.cpp"
#include <bits/stdc++.h>

using namespace std;

int main(){

    my_dynamic_array<int> arr(2);
    
    for (int i = 0 ; i <= 10 ; i++) {
        arr.add(i*2);
    }
    
    for (int i = 0 ; i < arr.size() ; ++i) {
        cout << arr.get(i) << '\n';
    }

    arr.clear();
    cout << "++++" << arr.size() << '\n';
    cout << "-----------------------\n";

    for (int i = 0 ; i <= 10 ; i++) {
        arr.add(i*2);
    }

    for (int i = 0 ; i < arr.size() ; ++i) {
        cout << arr.get(i) << '\n';
    }

    cout << "++++" << arr.size() << '\n';

    return 0;
}
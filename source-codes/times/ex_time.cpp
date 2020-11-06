#include<bits/stdc++.h>

using namespace std;

int main() {
    cout << "n?: ";
    int n;
    cin >> n;

    double r = 0;
    int sign = 1;
    for (int k = 1 ; k <= n ; k+=2){
        r += sign * (1.0/k);
        sign = -sign;
    }
    
    cout << setprecision (10) << fixed << r * 4 << '\n';

    return 0;
}


/*
ID: mckibbe1
TASK: ride
LANG: C++11
*/

// Problem: https://train.usaco.org/usacoprob2?a=bnfiDkB4n7g&S=ride

#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    int first = 1, second = 1;
    string a, b; cin >> a >> b;
    for(int i = 0; i < a.size(); i++) first = first * int(a[i] - 'A' + 1);
    for(int i = 0; i < b.size(); i++) second = second * int(b[i] - 'A' + 1);
    
    if (first % 47 == second % 47) {
        cout << "GO\n";
    } else {
        cout << "STAY\n";
    }

    return 0;
}
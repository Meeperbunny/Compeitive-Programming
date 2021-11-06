/*
ID: mckibbe1
TASK: gift1
LANG: C++11
*/

// Problem: https://train.usaco.org/usacoprob2?a=bnfiDkB4n7g&S=gift1

#include <iostream>
#include <string>

using namespace std;

int get_ind(string people[10], string name) {
    for(int i = 0; i < 10; i++) {
        if (name == people[i]) return i;
    }
}

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int NP; cin >> NP;
    string people[10];
    int balances[10];
    for(int i = 0; i < NP; i++) {
        cin >> people[i];
        balances[i] = 0;
    }
    for(int i = 0; i < NP; i++) {
        string curr_name; cin >> curr_name;
        int curr_ind = get_ind(people, curr_name);
        int val, num; cin >> val >> num;
        if (num == 0) {
            balances[curr_ind] += val;
            continue;
        }
        for(int q = 0; q < num; q++) {
            string name; cin >> name;
            int ind = get_ind(people, name);
            balances[ind] += int(val / num);
        }
        balances[curr_ind] -= int(val / num) * num;
    }

    // Once done, print
    for(int i = 0; i < NP; i++) {
        cout << people[i] << ' ' << balances[i] << '\n';
    }

    return 0;
} 
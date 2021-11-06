/*
ID: mckibbe1
TASK: friday
LANG: C++11
*/

// Problem: https://train.usaco.org/usacoprob2?a=bnfiDkB4n7g&S=friday

#include <iostream>
#include <string>

using namespace std;

int get_days(int year, int month) {
    int day_count[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 100 == 0 && year % 400 == 0) day_count[1] = 29;
    if (year % 100 != 0 && year % 4 == 0) day_count[1] = 29;
    return day_count[month];
}

pair<int, int> is_fri(int start_day, int days_in) {
    pair<int, int> ret;
    ret.first = (start_day + 12) % 7;
    ret.second = (start_day + days_in) % 7;
    return ret;
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int N; cin >> N;

    int count[7];
    for(int i = 0; i < 7; i++) count[i] = 0;
    int start_day = 2;
    for(int curr_year = 1900; curr_year < 1900 + N; curr_year++) {
        for(int month = 0; month < 12; month++) {
            int days = get_days(curr_year, month);
            pair<int, int> p(is_fri(start_day, days));
            count[p.first]++;
            start_day = p.second;
        }
    }

    for(int i = 0; i < 7; i++) {
        cout << count[i];
        if (i != 6) cout << ' ';
        else cout << '\n';
    }

    return 0;
} 
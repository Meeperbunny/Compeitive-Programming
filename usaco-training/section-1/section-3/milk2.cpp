/*
ID: mckibbe1
TASK: milk2
LANG: C++11
*/

// Problem: https://train.usaco.org/usacoprob2?a=bnfiDkB4n7g&S=milk2

#include <iostream>
#include <algorithm>

using namespace std;

struct Event {
    int time;
    int type;
    bool operator<(const Event &other) {
        if (time == other.time) {
            return type > other.type;
        }
        return time < other.time;
    }
};

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int N;
    cin >> N;
    Event events[10000];
    for(int i = 0; i < N; i++) {
        int start_time, end_time;
        cin >> start_time >> end_time;
        events[i * 2].type = 1;
        events[i * 2].time = start_time;
        events[i * 2 + 1].type = -1;
        events[i * 2 + 1].time = end_time;
    }

    sort(events, events + 2 * N);

    // Eval
    int longest_gap = 0;
    int longest_con = 0;

    int curr_time = events[0].time;
    int curr_count = 0;
    for(int i = 0; i < 2 * N; i++) {
        int next_time = events[i].time;
        if (curr_count == 0) {
            // If coming off of gap
            longest_gap = max(next_time - curr_time, longest_gap);
            curr_time = next_time;
        } 

        // Update
        curr_count += events[i].type;

        if (curr_count == 0) {
            // If coming into gap
            longest_con = max(next_time - curr_time, longest_con);
            curr_time = next_time;
        }
    }

    cout << longest_con << ' ' << longest_gap << endl;

    return 0;
} 
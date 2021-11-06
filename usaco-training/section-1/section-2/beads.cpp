/*
ID: mckibbe1
TASK: beads
LANG: C++11
*/

// Problem: https://train.usaco.org/usacoprob2?a=bnfiDkB4n7g&S=beads

#include <iostream>
#include <string>

using namespace std;

int mod(int changed, int mod) {
    return (changed + mod) % mod;
}

int to_color(char c) {
    if (c == 'w') return 0;
    if (c == 'b') return 1;
    if (c == 'r') return 2;
}

int get_count(string beads, int break_pos) {
    int size = beads.size();
    int left = mod(break_pos - 1, size), right = mod(break_pos, size);
    int l_color = to_color(beads[mod(break_pos - 1, size)]), r_color = to_color(beads[mod(break_pos, size)]);

    int count = 0;

    // Eval right
    for(int r = right;; r = mod(r + 1, size)) {
        int curr_color = to_color(beads[r]);
        if (r_color == 0) {
            r_color = curr_color;
        } else if (r_color != curr_color && curr_color != 0) {
            break;
        }
        count++;
        if (count >= size) return size;
    }

    // Eval left
    for(int l = left;; l = mod(l - 1, size)) {
        int curr_color = to_color(beads[l]);
        if (l_color == 0) {
            l_color = curr_color;
        } else if (l_color != curr_color && curr_color != 0) {
            break;
        }
        count++;
        if (count >= size) return size;
    }

    return count;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int N;
    string s;
    cin >> N >> s;

    int max = 0;
    for(int i = 0; i < N; i++) {
        int val = get_count(s, i);
        max = (max < val) ? val : max;
    }

    cout << max << endl;

    return 0;
} 
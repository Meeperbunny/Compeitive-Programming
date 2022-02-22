/*
ID: mckibbe1
TASK: transform
LANG: C++11
*/

// Problem: https://train.usaco.org/usacoprob2?a=bnfiDkB4n7g&S=transform

#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool eq(string a[10], string b[10], int N) {
    for(int i = 0; i < N; i++) for(int q = 0; q < N; q++) if (a[i][q] != b[i][q]) return false;
    return true;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int N;
    string before[10], after[10];
    string pat[10];
    string tmp[10];
    cin >> N;
    FOR(i, N) cin >> before[i];
    FOR(i, N) { cin >> after[i]; pat[i] = after[i]; tmp[i] = after[i]; }

    // T1
    FOR(i, N) FOR(q, N) pat[i][q] = before[q][N - 1 - i];
    if (eq(pat, after, N)) {
        cout << 1 << endl;
        return 0;
    }

    // T2
    FOR(i, N) FOR(q, N) pat[i][q] = before[N - 1 - i][N - 1 - q];
    if (eq(pat, after, N)) {
        cout << 2 << endl;
        return 0;
    }

    // T3
    FOR(i, N) FOR(q, N) pat[i][q] = before[N - 1 - q][i];
    if (eq(pat, after, N)) {
        cout << 3 << endl;
        return 0;
    }

    // T4
    FOR(i, N) FOR(q, N) pat[i][q] = before[i][N - 1 - q];
    if (eq(pat, after, N)) {
        cout << 4 << endl;
        return 0;
    }

    // T5
    FOR(i, N) FOR(q, N) tmp[i][q] = before[i][N - 1 - q];
    FOR(i, N) FOR(q, N) pat[i][q] = tmp[q][N - 1 - i];
    if (eq(pat, after, N)) {
        cout << 5 << endl;
        return 0;
    }

    // T5
    FOR(i, N) FOR(q, N) tmp[i][q] = before[i][N - 1 - q];
    FOR(i, N) FOR(q, N) pat[i][q] = tmp[N - 1 - i][N - 1 - q];
    if (eq(pat, after, N)) {
        cout << 5 << endl;
        return 0;
    }

    // T5
    FOR(i, N) FOR(q, N) tmp[i][q] = before[i][N - 1 - q];
    FOR(i, N) FOR(q, N) pat[i][q] = tmp[N - 1 - q][i];
    if (eq(pat, after, N)) {
        cout << 5 << endl;
        return 0;
    }

    // T6
    if (eq(before, after, N)) {
        cout << 6 << endl;
        return 0;
    }

    cout << 7 << endl;
    return 0;
} 
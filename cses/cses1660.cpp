/*
    CSES 1660 - Subarray Sums I
    https://cses.fi/problemset/task/1660
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, d; cin >> n >> d;

    ll v[n];
    for (int i = 0; i < n; i++) cin >> v[i];

    ll cnt = 0, sum = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && sum + v[r] <= d) {
            sum += v[r];
            r++;
        }

        if (sum == d) cnt++;
        sum -= v[l];
    }

    cout << cnt << '\n';

    return 0;
}
/*
    Codeforces 670D1 - Magic Powder
    https://codeforces.com/problemset/problem/670/D1
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, a[1123], have[1123];

bool isValid(ll x){
    ll res = 0;

    for (int i = 0; i < n; i++)
        res += max(a[i] * x - have[i], 0LL);
    
    return res <= k;
}

ll bs(){
    ll l = 0, r = *max_element(have, have+n)+k, m, ans = -1;

    while (l <= r){
        m = l + (r-l)/2;

        if (isValid(m)){
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m -1;
        }
    }

    return ans;
}

int main(){

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    for (int i = 0; i < n; i++)
        cin >> have[i];

    cout << bs() << endl;

    return 0;
}
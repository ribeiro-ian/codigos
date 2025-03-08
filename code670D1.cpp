/*
    Codeforces 670D1 - Magic Powder
    https://codeforces.com/problemset/problem/670/D1
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, k, a[1123], b[1123];

bool isValid(ll x){

    ll res = INT_MAX;
    for (int i = 0; i < n; i++){
        res = min(b[i]/a[i], res);
    }
    
    return x >= res;
}

ll bs(){
    ll l = 0, r = *max_element(b, b+n)+k, m, ans = -1;

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

    scanf("%lli %lli", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%lli", &a[i]);
        
    for (int i = 0; i < n; i++)
        scanf("%lli", &b[i]);

    printf("%lli\n", bs());

    return 0;
}

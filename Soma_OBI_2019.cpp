#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, k, cnt = 0;
    cin >> n >> k;

    vector <ll> v(n), pref(n+1);
    map <ll, ll> pref_cnt;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + v[i-1];

    // for (int i = 1; i <= n; i++)
    //     fprintf(stderr, "%i ", pref[i]);
    // fprintf(stderr, "\n");
    
    for (int i = 0; i <= n; i++){ // O(n)
        cnt += (pref_cnt[pref[i] - k]);
        pref_cnt[pref[i]] += 1;
    } 
    
    printf("%i\n", cnt);

    return 0;
}

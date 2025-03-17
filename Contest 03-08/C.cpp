/*
    Beecrowd 1523 - Estacionamento Linear
    https://judge.beecrowd.com/pt/problems/view/1523
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

int main(){
    int n, k, x, y;

    while (1){
        scanf("%i %i", &n, &k);

        if (n+k==0)break;

        stack <pii> est;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            scanf("%i %i", &x, &y);

            while (!est.empty() && est.top().second <= x)
                est.pop();            
            
            if (est.size() >= k)
                flag = false;
            else{
                if (est.empty())
                    est.push(make_pair(x,y));
                else if (y > est.top().second)
                {
                    flag = false;
                }
                else
                    est.push(make_pair(x,y));
            }
        }        

        printf("%s\n", flag ? "Sim" : "Nao");
    }

    return 0;
}

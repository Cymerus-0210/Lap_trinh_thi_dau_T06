// https://oj.vnoi.info/problem/olp_kc20_cows

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n,s;
    cin >> n >> s;
    cout << ((n+1)*n)/2 - s;

    return 0;
}

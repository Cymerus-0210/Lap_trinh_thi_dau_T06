// https://oj.vnoi.info/problem/olp_kc23_triangle

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long double u,v,s;
    cin >> u >> v;
    s = (u*u + v*v)/4;
    cout << setprecision(2) << fixed << s;
    return 0;
}

// https://oj.vnoi.info/problem/olp_kc21_encryption

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    long l,r,a,k;
    cin >> l >> r >> a >> k;
    long h = __gcd(a,k) , x=k/h , dem=0;
    long tmp=x;
    for (auto i=1 ; tmp<=r ; i++ , tmp=x*i)
    {
        if (x*i>=l) dem++;
    }
    cout << dem;
    return 0;
}
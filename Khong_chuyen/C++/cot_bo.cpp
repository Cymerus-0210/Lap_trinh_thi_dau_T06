// https://oj.vnoi.info/problem/olp_kc19_cow

#include<bits/stdc++.h>
using namespace std;

long double kc(long long xa, long long ya, long long xb, long long yb)
{
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

long long bk(long double a, long double b)
{
    long long x=(long long)a;
    if (x*10 == a*10)
        return (long long)(a-b-1);
    else
        return (long long)a-(long long)b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n,a,b;
    cin >> n >> a >> b;
    long long m= LLONG_MAX;
    for (auto i=0 ; i<n ; i++)
    {
        long long x,y,r;
        cin >> x >> y >> r;
        m = min( m , bk( kc(a,b,x,y) , r));
    }
    cout << m;

    return 0;
}

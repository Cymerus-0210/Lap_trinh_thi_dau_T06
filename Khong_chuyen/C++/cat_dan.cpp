// https://oj.vnoi.info/problem/olp_kc22_cutpaste

#include<bits/stdc++.h>
using namespace std;

long long d(long long a, long long b, long long c, long long d)
{
    return (a-c)*(a-c) + (b-d)*(b-d);
}
vector<long long> mat_d(vector<long long> a) {
    vector<long long> res;
    res.push_back(d(a[0], a[1], a[2], a[3]));
    res.push_back(d(a[0], a[1], a[4], a[5]));
    res.push_back(d(a[0], a[1], a[6], a[7]));
    res.push_back(d(a[2], a[3], a[4], a[5]));
    res.push_back(d(a[2], a[3], a[6], a[7]));
    res.push_back(d(a[4], a[5], a[6], a[7]));
    sort(res.begin(), res.end());
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<long long> a(8);
    for (auto i = 0; i < 8; ++i) cin >> a[i];
    a = mat_d(a);

    long long t;
    cin >> t;

    long long dem = 0;
    for (auto i = 0; i < t; ++i) {
        vector<long long> b(8);
        for (auto j = 0; j < 8; ++j) cin >> b[j];
        b = mat_d(b);
        if (a == b) dem++;
    }

    cout << dem;

    return 0;
}
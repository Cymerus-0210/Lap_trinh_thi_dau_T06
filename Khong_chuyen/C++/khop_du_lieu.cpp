#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,k;
    cin >> n >> k;
    long long a[n];
    for (auto &x:a) cin >> x;
    for (auto i=0 ; i<n ; i++) 
    {
        long long x; cin >> x;
        a[i]=abs(a[i]-x);
    }
    // lý thuyết a % m = b % m => hiệu của a và b chia hết cho m
    // để tránh số âm ta dùng phép trị tuyệt đối abs
    // quy về bài toán tìm ước chung lớn nhất trong đoạn
    long long f[20][n];
    // kỹ thuật bảng thưa sprase table
    for (auto i=0 ; i<n ; i++)
        f[0][i]=a[i];
    for (auto i=1 ; i<20 ; i++)
    {
        for (auto j=0 ; j + (1<<i) <=n ; j++) //phép toán bitwise 1 << x tương đương 2 mũ x
        {
            f[i][j]=__gcd(f[i-1][j],f[i-1][j+(1 << (i-1))]);
        }
    }

    while (k--)
    {
        long long l,r;
        cin >> l >> r;
        l--,r--;
        long long k1 = log2(r-l+1);
        cout << __gcd(f[k1][l],f[k1][r-(1 << k1)+1]) << endl ;
    }

    return 0;
}

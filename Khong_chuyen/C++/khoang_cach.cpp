// https://oj.vnoi.info/problem/olp_kc21_distance

// ý tưởng tương tự như bài khop_du_lieu thay phép gcd thành lấy min
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long m,n,k;
    cin >> m >> n >>k;
    int a[m];
    int distance_a[m];
    int b[n];

    for (auto &x:a) cin >> x;
    for (auto &x:b) cin >> x;   
    sort(b,b+n);
    for (int i=0 ; i<m ; i++)
    {
      int it=lower_bound(b,b+n,a[i])-b;
      int x1=abs(a[i]-(b[it])); 
      int x2=abs(a[i]-b[it-1]);
      distance_a[i]=min(x1,x2);
    }
    // xây dựng bảng thưa sprase table
    int f[20][m];
    for (int i=0 ; i<m ; i++) f[0][i]=distance_a[i];
    for (int i=1 ; i<20; i++)
        for (int j=0 ; j<= m-(1<<i) ; j++)
            f[i][j]=min(f[i-1][j],f[i-1][j+(1 << (i-1))]);
    while(k--)
    {
        int l,r;
        cin >> l >> r; 
        l--,r--;
        int kc = log2(r-l+1);
        cout << min(f[kc][l],f[kc][r-(1<<kc)+1]) << endl;
    }
    return 0;
}

// https://oj.vnoi.info/problem/olp_kc22_smartshop

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll maxn=100000000 , N=500005;
ll n,m,l,r,res;
vector<ll> a,b;
bool f[100000000];
// để có thể lưu trữ hết các số thì phải khai báo mảng f ngoài main
int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    for (auto &x:f) x=false;
    f[1]=true;
    // ý tưởng của bài này là tạo ra mảng f lưu trữ các số lý tưởng theo đề bài
    // đó là các số có giá trị là luỹ thừa của 2, 3, 5
    for (auto i=2 ; i<maxn ; i=i*2) f[i]=true;
    for (auto i=3 ; i<maxn ; i=i*3) f[i]=true;
    for (auto i=5 ; i<maxn ; i=i*5) f[i]=true;
    cin >> n >> m ;
    for (auto i=0 ; i<n ; i++)
    {
        ll x; cin >> x;
        if (f[x])
        a.push_back(x);
    }    
    // sau khi có mảng tham chiếu f thì ta kiểm tra các giá trị đầu vào có phải là luỹ thừa của 2, 3, 5 không? 
    // nếu có thì đưa vào a
    sort(a.begin(),a.end());
    // sắp xếp lại a từ bé đến lớn
    while (m--)
    {
        // đếm từng giá trị phù hợp cần đếm trong mảng a 
        // đó là những số có giá trị lớn hơn l và bé hơn r 
        cin >> l >> r;
        res=0;
        for (auto x:a)
        {
            if (x>r) break;
            else if (x>=l) res++;
        }
        cout << res << endl;
    }
    return 0;
}

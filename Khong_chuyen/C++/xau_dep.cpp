// https://oj.vnoi.info/problem/olp_kc23_beastr

#include<bits/stdc++.h>
using namespace std;
long long cnt[26][1000001];
// lưu ý phải khai báo mảng này ở ngoài hàm main để tránh lỗi và có kết quả đúng
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    string s;
    cin >> n >> q;
    cin >> s;
    for (auto i=0 ; i<n ; i++)
        cnt[s[i]-'a'][i]=1;

    for (auto i=0 ; i<26 ; i++)
        for (auto j=0 ; j<n ; j++)
            cnt[i][j] += cnt[i][j-1];

// đếm từ 0 đến j thì chữ có mã i xuất hiện bao nhiêu lần và lưu vào cnt
// mã ở đây quy ước 0 là a, 1 là b, 2 là c,...
// ví dụ cnt[3][4] = 3 nghĩa là trong xâu s từ s[0] đến s[4] chữ d xuất hiện 3 lần 

    while(q--)
    {
        int i,j;
        cin >> i >> j;
        int tmp=0;
        // đếm từ i đến j có bao nhiêu chứ cái có số lần xuất hiện là lẻ

        for (auto t=0 ; t<26 ; t++)
            if ((cnt[t][j] - cnt[t][i-1]) % 2 == 1)
                tmp++;
        cout << tmp/2 << endl;
    }
    return 0;
}

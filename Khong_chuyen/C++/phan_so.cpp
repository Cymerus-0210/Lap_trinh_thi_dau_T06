#include <bits/stdc++.h>
using namespace std;

const int m = 1000000;
int nt[m + 5];
int L[m + 5];
// hàm sàng nguyên tố
void sang() 
{
    for (int i = 2; i <= m + 1; i++) 
    {
        if (nt[i] == 0) 
        {
            for (int j = 2 * i; j <= m; j += i) 
            {
                nt[j] = i;
            }
            nt[i] = i;
        }
    }
}
// ý tưởng là phân tích số nguyên tố của tử và mẫu
// mảng L lưu lại số lần xuất hiện của số i trên tử số 
// sau đó đếm và trừ dần với số nguyên tố dưới mẫu
// sau đó nếu L âm thì là số i sau khi rút gọn sẽ còn lại dưới mẫu và không được rút gọn
// nếu L âm và xuất hiện bất kỳ số nào khác 2 hoặc 5 dưới mẫu mà chưa được rút gọn thì đó là số thập phân vô hạn tuần hoàn
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sang();

    int t;
    cin >> t;
    while (t--) 
    {
        for (int i = 0; i <= m + 1; i++) L[i] = 0;
        int n;
        cin >> n;
        int data[2 * m]; 
        for (int i = 0; i < 2 * n; i++) cin >> data[i];

        for (int i = 0; i < n; i++) 
        {
            int k = data[i];
            if (k == 1) continue;
            while (k > 1) 
            {
                L[nt[k]]++;
                k /= nt[k];
            }
        }

        for (int i = 0; i < n; i++) 
        {
            int k = data[i + n];
            if (k == 1) continue;
            while (k > 1) 
            {
                L[nt[k]]--;
                k /= nt[k];
            }
        }

        bool res = false;
        for (int i = 3; i <= m; i++) 
        {
            if (L[i] < 0 && i != 5) 
            {
                res = true;
                break;
            }
        }

        if (res) cout << "repeating\n";
        else cout << "finite\n";
    }

    return 0;
}

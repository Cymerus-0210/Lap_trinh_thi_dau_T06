// https://oj.vnoi.info/problem/olp_kc20_buildcol
#include<bits/stdc++.h>
using namespace std;

long long n,M;
long long a[100005];
long long b[100005];

bool check (long long m)
{
    long long con_lai=0;
    // a là độ cao các cột
    // b là lượng nước tối đa mà cột đó có thể chứa được nếu không có cột nào ngoại trừ cột đầu và cột cuối chính là độ cao cột vì 2 ô này không chứa được nước
    // từ đó suy ra b[i] - a[i] sẽ là lượng nước thực tế trong ô thứ i
    for (auto i=1 ; i<=n ; i++)
    {
        long long nuoc = b[i]-a[i];
        long long tran_ra = max( (long long)0 , (min(m , b[i]) - a[i]));
        // sau khi nâng lên m thì tại ô thứ i tràn ra bao nhiêu nước
        // vì nâng cột lên tối đa là m
        // nếu m nhỏ hơn b[i] mà m - a[i] dương nghĩa là tại a[i] đang thấp hơn m và cần nâng thêm m-a[i] đồng nghĩa với việc tràn ra m-a[i] đơn vị nước
        // nếu m nhỏ hơn b[i] mà m - a[i] không dương nghĩa là tại a[i] đang cao hơn hoặc bằng m nên lượng nước tràn ra là 0
        con_lai += nuoc - tran_ra;
        // tính lượng nước còn lại là nước ban đầu trừ nước tràn ra
        if (con_lai >= M)
            return true; //tại một thời điểm bất kỳ mà nước còn lại thoả mãn lớn hơn bằng M thì trả về true ngay lập tức
    }
    return false; //nếu cộng hết lượng nước còn lại mà không thoả thì trả về false
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> M;
    for (auto i=1 ; i<=n ; i++)
        cin >> a[i];

    long long tmp = 0;
    for (auto i=1 ; i<=n ; i++)
    {
        if (tmp < a[i]) tmp = a[i];
        b[i] = tmp;
    }
    tmp = 0;
    for (auto i=n ; i>=1 ; i--)
    {
        if (tmp<a[i]) tmp = a[i];
        b[i] = min(b[i],tmp);
    }
    // vì tìm m lớn nhất, nếu m càng tăng thì lượng nước còn lại càng giảm => hàm đơn điệu => tìm kiếm nhị phân binary search
    long long res = -1;
    long long mn = *min_element(a + 1, a + n + 1);
    long long mx = *max_element(a + 1, a + n + 1);
    long long l=mn, r=mx;
    while(l<=r)
    {
        long long mid = (l+r)>>1; // phép toàn bitwise >>1 tương đương với chia 2 lấy phần nguyên
        if (check(mid))
        {
            res=mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << res;

    return 0;
}
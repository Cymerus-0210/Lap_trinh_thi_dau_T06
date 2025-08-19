#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    long long a[n];
    for (auto &x:a) cin >> x;

    long long L[n] , R[n];

    stack<pair<long long,long long>> st;
    long long sum=0;


    // ý tưởng:
    // duyệt qua từng phần tử trong mảng a
    // việc lựa chọn bi <= ai nên để tối ưu thì ta sẽ cố cho bi=ai
    // thêm cặp phần tử vào stack, thêm đếm số lượng
    // xét đến phần tử tiếp theo 
    // nếu lớn hơn phần tử liền trước nó thì vẫn có thể chọn bằng ai
    // nếu nhỏ hơn hoặc bằng thì ta sẽ chọn phần tử chỗ đó bằng ai
    // và tất cả các phần tử từ 0 đến i-1 sẽ cho bằng ai cả
    // mảng L sẽ lưu tổng các phần tử bi từ 0 đến i
    // mảng L sẽ xét một chuỗi bi không tăng theo chiều từ 0 đến n-1

    // ý tưởng tương tự, thuật toán tương tự nhưng làm theo chiều từ n-1 về 0 ta sẽ được 1 chuỗi bi không giảm và lưu vào R 
    for (auto i=0 ; i<n ; i++){
        long long val = a[i] , cnt = 1;
        while (st.empty()==false and st.top().first >= val){
            sum -= st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        st.push({val,cnt});
        sum += val * cnt;
        L[i]=sum;
    }
    st = stack<pair<long long,long long>>();
    sum=0;
    for (auto i=n-1 ; i>=0 ; i--){
        long long val = a[i] , cnt = 1;
        while (st.empty()==false and st.top().first >= val){
            sum -= st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        st.push({val,cnt});
        sum += val * cnt;
        R[i]=sum;
    }
    // để có được kết quả tối ưu khi xét tại mỗi vị trí ta lấy L[i] + R[i]
    // khi đó L[i] = b0 + b1 + b2 + ... + bi tối ưu theo chiều tăng từ phải qua trái
    // con R[i] = bn-1 + bn-2 + bn-3 + ... + bi tối ưu theo chiều tăng từ phải qua trái
    // dễ thấy bi được cộng 2 lần mà bi thì bằng ai nên ta trừ thêm 1 lần ai
    long long res = 0;
    for (auto i=0 ; i<n ; i++){
        res = max (res , (L[i]+R[i]-a[i]));
    }
    cout << res;
    return 0;
}
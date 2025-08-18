#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 21;
const int mod=1e9+7;
bool snt[maxn];
long long n,k;
// vì kết quả của output không lớn hơn n
// vậy nên khi 2 luỹ thừa hoặc nhân lại mà lớn hơn n thì return n+1
long long mul(long long a, long long b){
  if(a==0 or b==0)return 0;
  if(a>n/b)return n+1;
  return a*b;
}
// luỹ thừa ấn độ
// áp dụng hàm nhân ở trên để kiểm soát giá trị không lớn hơn n 
long long binpow(long long n, int k){
  if(k==0)return 1;
  long long a=binpow(n, k/2);
  if(k%2==0)return mul(a, a);
  else return mul(mul(a, a), n);
}
// hai hàm trên dùng để xử lý số lớn 

// hàm sàng số nguyên tố
void sang() {
    fill(snt, snt + maxn, true);
    snt[0] = snt[1] = false;
    for (int i = 2; i * i < maxn; i++) {
        if (snt[i]) {
            for (int j = i * i; j < maxn; j += i) {
                snt[j] = false;
            }
        }
    }
}

// khai báo tổ hợp 3 số mũ t1,t2,t3 trong đề bài
struct ba_so_ke{
    int i;
    int j;
    int t;
};

// phân tích:
// để m có đúng k ước mà m = p1^t1 * p2^t2 * p3^t3 với p1,p2,p3 là 3 số nguyên tố liên tiếp thì:
// k = (t1+1)*(t2+1)*(t3+1)
// lý do là dùng tổ hợp để nhóm các số nguyên tố lại thành ước của m 
// thêm ước 1 nữa 
// ta có biểu thức:
// t1*t2*t3 + t1*t2 + t1*t3 + t2*t3 + t1 + t2 + t3 + 1 
// rút gọn lại thành (t1+1)*(t2+1)*(t3+1)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    sang();
    vector<int> so_nguyen_to;
    for (auto i=2 ; i<maxn ; i++){
        if (snt[i]) so_nguyen_to.push_back(i);
    }
    cin >> n >> k;
    vector<ba_so_ke> div; 
    for (auto i=2 ; i<=57 ; i++)
        for (auto j=2 ; j<=57 ; j++)
            for (auto t=2 ; t<=57 ; t++)
                if (i*j*t==k){
                    ba_so_ke x;
                    x.i=i;
                    x.j=j;
                    x.t=t;
                    div.push_back(x);
                }
    long long ans=0;
    for (auto i=0 ; i<so_nguyen_to.size()-2 ; i++)
        for (auto x:div){
            long long pow1 = binpow(so_nguyen_to[i], x.i-1);
            long long pow2 = binpow(so_nguyen_to[i+1], x.j-1);
            long long pow3 = binpow(so_nguyen_to[i+2], x.t-1);
            long long m = mul(pow1,mul(pow2,pow3));
            if (m<=n and m>ans) ans=m;
        }
    cout << ans;
    return 0;
}
import sys
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
input = sys.stdin.readline

maxn = int(1e6 + 21)
mod = int(1e9 + 7)
snt = [True] * maxn
n = 0
k = 0

# vì kết quả của output không lớn hơn n
# vậy nên khi 2 luỹ thừa hoặc nhân lại mà lớn hơn n thì return n+1
def mul(a, b):
    if a == 0 or b == 0:
        return 0
    if a > n // b:
        return n + 1
    return a * b

# luỹ thừa ấn độ
# áp dụng hàm nhân ở trên để kiểm soát giá trị không lớn hơn n 
def binpow(n, k):
    if k == 0:
        return 1
    a = binpow(n, k // 2)
    if k % 2 == 0:
        return mul(a, a)
    else:
        return mul(mul(a, a), n)
# hai hàm trên dùng để xử lý số lớn 

# hàm sàng số nguyên tố
def sang():
    global snt
    snt[0] = snt[1] = False
    i = 2
    while i * i < maxn:
        if snt[i]:
            j = i * i
            while j < maxn:
                snt[j] = False
                j += i
        i += 1

#  phân tích:
#  để m có đúng k ước mà m = p1^t1 * p2^t2 * p3^t3 với p1,p2,p3 là 3 số nguyên tố liên tiếp thì:
#  k = (t1+1)*(t2+1)*(t3+1)
#  lý do là dùng tổ hợp để nhóm các số nguyên tố lại thành ước của m 
#  thêm ước 1 nữa 
#  ta có biểu thức:
#  t1*t2*t3 + t1*t2 + t1*t3 + t2*t3 + t1 + t2 + t3 + 1 
#  rút gọn lại thành (t1+1)*(t2+1)*(t3+1)

sang()
so_nguyen_to = []
for i in range(2, maxn):
    if snt[i]:
        so_nguyen_to.append(i)

n,k = map(int,input().split())
div=[]

for i in range(2, 58):
    for j in range(2, 58):
        for t in range(2, 58):
            if i * j * t == k:
                div.append([i,j,t])
ans = 0

for i in range(len(so_nguyen_to)-2):
    for x in div:
        pow1 = binpow(so_nguyen_to[i], x[0] - 1)
        pow2 = binpow(so_nguyen_to[i + 1], x[1] - 1)
        pow3 = binpow(so_nguyen_to[i + 2], x[2] - 1)
        m = mul(pow1, mul(pow2, pow3))
        if m <= n and m > ans:
            ans = m
print(ans)
import sys
# sys.stdin = open("input.in", "r")
# sys.stdout = open("output.out", "w")
input = sys.stdin.readline

from collections import deque
n=int(input())
a=list(map(int,input().split()))

L=[0 for i in range(n)]
R=[0 for i in range(n)]

st=deque()
tmp=0

# ý tưởng:
# duyệt qua từng phần tử trong mảng a
# việc lựa chọn bi <= ai nên để tối ưu thì ta sẽ cố cho bi=ai
# thêm cặp phần tử vào stack, thêm đếm số lượng
# xét đến phần tử tiếp theo 
# nếu lớn hơn phần tử liền trước nó thì vẫn có thể chọn bằng ai
# nếu nhỏ hơn hoặc bằng thì ta sẽ chọn phần tử chỗ đó bằng ai
# và tất cả các phần tử từ 0 đến i-1 sẽ cho bằng ai cả
# mảng L sẽ lưu tổng các phần tử bi từ 0 đến i
# mảng L sẽ xét một chuỗi bi không tăng theo chiều từ 0 đến n-1

# ý tưởng tương tự, thuật toán tương tự nhưng làm theo chiều từ n-1 về 0 ta sẽ được 1 chuỗi bi không giảm và lưu vào R 

for i in range(n):
    val = a[i]
    cnt = 1
    while st and st[-1][0] >= val:
        tmp -= st[-1][0] * st[-1][1]
        cnt += st[-1][1]
        st.pop()
    st.append([val,cnt])
    tmp += val * cnt
    L[i]=tmp


st.clear()
tmp=0
for i in range(n-1,-1,-1):
    val = a[i]
    cnt = 1
    while st and st[-1][0] >= val:
        tmp -= st[-1][0] * st[-1][1]
        cnt += st[-1][1]
        st.pop()
    st.append([val,cnt])
    tmp += val * cnt
    R[i]=tmp

# để có được kết quả tối ưu khi xét tại mỗi vị trí ta lấy L[i] + R[i]
# khi đó L[i] = b0 + b1 + b2 + ... + bi tối ưu theo chiều tăng từ phải qua trái
# con R[i] = bn-1 + bn-2 + bn-3 + ... + bi tối ưu theo chiều tăng từ phải qua trái
# dễ thấy bi được cộng 2 lần mà bi thì bằng ai nên ta trừ thêm 1 lần ai

res = 0
for i in range(n):
    res = max(res, (L[i]+R[i]-a[i]))
print(res)
# https://oj.vnoi.info/problem/olp_kc22_smartshop

import sys
input = sys.stdin.readline
maxn=100000000
f = bytearray(maxn) 
# vì lý do bộ nhớ nên phải lưu trữ nên phải khởi tạo list f bằng cách này để mỗi phần tử chỉ tốn 1 byte
# mặc định của python mỗi phần tử sẽ tốn 28 bytes 
# vì giá trị trong f chỉ lưu 1 hoặc 0 (True hoặc False) nên chỉ cần 1 byte
f[1]=1
# ý tưởng của bài này là tạo ra mảng f lưu trữ các số lý tưởng theo đề bài
# đó là các số có giá trị là luỹ thừa của 2, 3, 5
tmp=2
while tmp<maxn:
    f[tmp]=1
    tmp*=2
tmp=3
while tmp<maxn:
    f[tmp]=1
    tmp*=3
tmp=5
while tmp<maxn:
    f[tmp]=1
    tmp*=5
n,m = map(int,input().split())
a = list(map(int,input().split()))
b=[]
for i in a:
    if f[i]:
        b.append(i)
# sau khi có mảng tham chiếu f thì ta kiểm tra các giá trị đầu vào có phải là luỹ thừa của 2, 3, 5 không? 
# nếu có thì đưa vào b
b.sort()
# sắp xếp lại b từ bé đến lớn
for _ in range(m):
    # đếm từng giá trị phù hợp cần đếm trong list b 
    # đó là những số có giá trị lớn hơn l và bé hơn r 
    l,r = map(int,input().split())
    res=0
    for i in b:
        if i>r:
            break
        elif i>=l:
            res+=1
    print(res)

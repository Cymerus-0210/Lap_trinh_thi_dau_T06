# https://oj.vnoi.info/problem/olp_kc19_seq

import math

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
m = [abs(a[i]-b[i]) for i in range(n)]
# lý thuyết a % m = b % m => hiệu của a và b chia hết cho m
# để tránh số âm ta dùng phép trị tuyệt đối abs
# quy về bài toán tìm ước chung lớn nhất trong đoạn
f = [[0] * n for _ in range(20)]
# kỹ thuật bảng thưa sprase table
for i in range(n):
    f[0][i] = m[i]

for i in range(1, 20):
    for j in range(n - (1 << i) + 1): # phép toán bitwise 1 << x tương đương 2 mũ x
        f[i][j] = math.gcd(f[i - 1][j], f[i - 1][j + (1 << (i - 1))])
for _ in range(k):
    l, r = map(int, input().split())
    l, r = l - 1, r - 1
    k_val = int(math.log2(r - l + 1))
    print(math.gcd(f[k_val][l], f[k_val][r - (1 << k_val) + 1]))

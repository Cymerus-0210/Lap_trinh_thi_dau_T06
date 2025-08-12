# https://oj.vnoi.info/problem/olp_kc22_abstract

n,m=map(int,input().split())
a=[]
for _ in range(n):
    a.append(list(map(int,input().split())))
b = [[0 for _ in range(m)] for __ in range(n)]

for i in range(n):
    if a[i][0] > 0:
        b[i][0] = 1
    if a[i][m-1] > 0:
        b[i][m-1] = 1

for j in range(m):
    if a[0][j] > 0:
        b[0][j] = 1
    if a[n-1][j] > 0:
        b[n-1][j] = 1

for i in range(n):
    mx = a[i][0]
    for j in range(m):
        if a[i][j] > mx:
            mx = a[i][j]
            b[i][j] = 1

for i in range(n):
    mx = a[i][m-1]
    for j in range(m-1,0,-1):
        if a[i][j] > mx:
            mx = a[i][j]
            b[i][j] = 1

for j in range(m):
    mx = a[0][j]
    for i in range(n):
        if a[i][j] > mx:
            mx = a[i][j]
            b[i][j] = 1

for j in range(m):
    mx = a[n-1][j]
    for i in range(n-1,0,-1):
        if a[i][j] > mx:
            mx = a[i][j]
            b[i][j] = 1

print(sum(row.count(1) for row in b))
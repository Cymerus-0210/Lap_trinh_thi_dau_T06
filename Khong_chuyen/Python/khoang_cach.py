# https://oj.vnoi.info/problem/olp_kc21_distance

import bisect,math,sys
input = sys.stdin.readline
# tương tự như 
'''ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);'''
# của c++

# ý tưởng tương tự như bài khop_du_lieu thay phép gcd thành lấy min

m,n,k = map(int,input().split())
a = list(map(int,input().split()))
b = sorted(list(map(int,input().split())))
distance_a=[]
for i in range(m):
    it = bisect.bisect_left(b,a[i])  # tương tự như lower_bound
    x1 = abs( a[i] - b[it] ) if it < n else float('inf')
    x2 = abs ( a[i] - b[it-1] ) if it > 0 else float('inf')
    distance_a.append(min(x1,x2))

f = [[0 for i in range(m)] for j in range(20)]
for i in range(m):
    f[0][i] = distance_a[i]
# xây dựng bảng thưa sprase table
for i in range(1,20):
    for j in range(m-(1<<i)+1):
        f[i][j] = min(f[i-1][j] , f[i-1][j + (1<<(i-1))])
for _ in range(k):
    l,r = map(int,input().split())
    l-=1
    r-=1
    kc = int(math.log2(r-l+1))
    print(min(f[kc][l],f[kc][r-(1<<kc)+1]))

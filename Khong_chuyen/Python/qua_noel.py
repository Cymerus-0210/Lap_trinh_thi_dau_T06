
# https://oj.vnoi.info/problem/olp_kc22_noelgift

# ý tưởng của bài này là xem 1 món quà là 1 điểm trong đồ thì
# 1 bé là 1 cạnh trong đồ thị
# như thế thì mỗi bé sẽ nối với 2 món quà
# sau khi xây dựng đồ thì sẽ tìm xem có cách nào để chia cắt đồ thị ra thành nhiều phần trong đó số đỉnh vẫn còn được nối với cạnh là nhiều nhất

import sys
sys.setrecursionlimit(200000)
# tăng giới hạn đệ quy lên 200000 vì có n <= 100000 nên tối đa có thể dẫn tới 100000 lần đệ quy, dòng lệnh này để tránh lỗi tràn đệ quy trong python

qua = [[] for _ in range(100005)] 
# mảng này lưu các đỉnh của đồ thị tương đương với các món quà 
# ví dụ vị trí qua[1] = [2, 4, 3] thì có nghĩa là món quà số 1 có 3 bé thích trong đó nó sẽ được ghép cặp với các món quà số 2, 4, 3
be = [0] * 100005
# đây là số bậc của đồ thị tương ứng với các cạnh và tương ứng với số các bé trong đề bài 
# ví dụ be[1] = 3 đồng nghĩa với việc có 3 bé thích món quà số 1
visited = [False] * 100005
# mảng visited để thực thi thuật toán dfs
n, m = map(int, input().split())

for _ in range(m):
    u, v = map(int, input().split())
    qua[u].append(v)
    qua[v].append(u)
    be[u] += 1
    be[v] += 1
# nhập dữ liệu
ans = 0
so_be = 0
so_mon_qua = 0

# hàm dfs dùng để tìm ra thứ tự phát các món quà tối ưu
def dfs(u):
    global so_be, so_mon_qua
    so_be += be[u]
    so_mon_qua += 1
    visited[u] = True
    for v in qua[u]:
        if not visited[v]:
            dfs(v)

for i in range(1, n + 1):
    if not visited[i]:
        so_be = 0
        so_mon_qua = 0
        dfs(i)
        ans += min(so_mon_qua, so_be // 2)
        # nếu có nhiều quà hơn số bé thì cũng chỉ phát được cho từng đó bé
        # nếu có nhiều bé hơn quà thì cũng chỉ phát được từng đó quà
        # nên lấy min của 2 giá trị

print(ans)

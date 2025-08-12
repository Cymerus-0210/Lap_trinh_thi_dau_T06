# https://oj.vnoi.info/problem/olp_kc23_triangle

u, v = map(int, input().split(" "))
s = u * u + v * v
print(f"{s // 4}.{s % 4 * 25:02d}")

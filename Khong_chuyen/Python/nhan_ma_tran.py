import sys
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
input = sys.stdin.readline


k, n, hang, cot, S = map(int, input().split())
matrices = []
for _ in range(k):
    matrix = [list(map(int, input().split())) for _ in range(n)]
    matrices.append(matrix)
hang-=1
cot-=1

mat_h=matrices[0][hang]
for i in range(1,k):
    res=[0 for __ in range(n)]    
    for c in range(n):
        for h in range(n):
            res[c] += mat_h[h] * matrices[i][h][c]
            res[c] %= S    
    mat_h=res[:]

print(mat_h[cot])

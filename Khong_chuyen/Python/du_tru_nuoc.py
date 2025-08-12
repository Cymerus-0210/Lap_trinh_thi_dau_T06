import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")




n,M = map(int,input().split())
a = [0 for _ in range(n+2)]
b = [0 for _ in range(n+2)]
# print(b)
c = list(map(int,input().split()))


def check(m):
    global n,a,b,M
    remain = 0
    
    for i in range(1,n+1):
        water = b[i]-a[i]
        drain = max(0,min(m, b[i])-a[i])
        remain += water-drain
        if remain >= M:
            return True
    return False


for i in range(1,n+1):
    a[i]=c[i-1]

# print(a)

pref = 0
for i in range(1,n+1):
    if pref < a[i]:
        pref=a[i]
    b[i]=pref

# print(b)
suff=0
for i in range(n,0,-1):
    if suff < a[i]:
        suff = a[i]
    b[i] = min(b[i],suff)
# print(b)

res = -1
mx = max(a[1:n+1])
mn = min(a[1:n+1])
l=mn
r=mx
while l<=r:
    m = (l+r)>>1
    if check(m):
        res = m
        l = m+1
    else:
        r = m-1
print(res)
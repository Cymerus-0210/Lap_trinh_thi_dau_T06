m=1000000
nt=[0]*(m+2)
# hàm sàng nguyên tố
def sang():
    global nt , m
    for i in range(2,m+2):
        if nt[i] == 0:
            for j in range(2*i,m+1,i):
                nt[j] = i
            nt[i]=i
sang()
t=int(input())

for _ in range(t):
    L=[0]*(m+2)
    n, *data = map(int, input().split())
    for i in range(n):
        k=data[i]
        if k==1:
            continue
        while k>1:
            L[nt[k]]+=1;
            k//=nt[k]
    for i in range(n):
        k=data[i+n]
        if k==1:
            continue
        while k>1:
            L[nt[k]]-=1;
            k//=nt[k]
    
    res=any(L[i] < 0 and i != 5 for i in range(3, m + 1))
    if res:
        print('repeating')
    else:
        print('finite')

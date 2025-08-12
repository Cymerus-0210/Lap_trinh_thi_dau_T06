# https://oj.vnoi.info/problem/olp_kc19_tri

n ,k = map(int,input().split())
d = list(map(int,input().split()))
count = 0
maxk = 0
sum = 0
for i in range(n):
    if i < k:
        if d[i] > maxk:
            sum = sum + maxk
            if d[i] != 0:
                maxk = d[i]
        else:
            sum = sum + d[i]
        if i == k-1:
            if sum > maxk:
                count += 1
    else:
        if maxk == d[i-k]:
            sum = sum + d[i]
            maxk = max(d[i-k+1:i+1])
            sum = sum - maxk
        else:
            sum = sum - d[i - k]
            if d[i] > maxk:
                sum = sum + maxk
                maxk = d[i]
            else:
                sum = sum + d[i]

        if sum > maxk:
            count += 1
print(count)
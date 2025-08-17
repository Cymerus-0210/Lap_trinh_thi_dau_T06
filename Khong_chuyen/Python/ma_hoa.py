# https://oj.vnoi.info/problem/olp_kc21_encryption

from math import gcd

l,r,a,k=map(int,input().split())
h=gcd(a,k)
x=k//h
dem=0
i=1
temp=x
while temp<=r:
	if x*i>=l:
		dem+=1
	i+=1
	temp=x*i
print(dem)

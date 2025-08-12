# https://oj.vnoi.info/problem/olp_kc19_cow

import math

def kc(xa,ya,xb,yb):
	return math.sqrt((xa-xb)**2+(ya-yb)**2)
def bk(a,b):
	x=int(a)
	if x*10 == a*10:
		return int(a-b-1)
	else:
		return int(a)-int(b)

n,a,b=map(int,input().split())
m=math.inf
for _ in range(n):
	x,y,r=map(int,input().split())
	m=min(m,bk(kc(a,b,x,y),r))
print(m)

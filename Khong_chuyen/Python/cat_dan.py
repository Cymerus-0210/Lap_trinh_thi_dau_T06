# https://oj.vnoi.info/problem/olp_kc22_cutpaste

flag = True

# hàm tính khoảng cách giữa 2 điểm trông mặt phẳng toạ độ Oxy
def d(a,b,c,d):
    return (a-c)**2+(b-d)**2

# tính độ dài 4 cạnh và 2 đường chéo của tứ giác sau đó sắp xếp từ nhỏ đến lớn
def mat_d(a):
    res=[]
    res.append(d(a[0],a[1],a[2],a[3]))
    res.append(d(a[0],a[1],a[4],a[5]))
    res.append(d(a[0],a[1],a[6],a[7]))
    res.append(d(a[2],a[3],a[4],a[5]))
    res.append(d(a[2],a[3],a[6],a[7]))
    res.append(d(a[4],a[5],a[6],a[7]))
    res.sort()
    return res
dem=0
try:
    a=mat_d(list(map(int,input().split())))
except:
    flag=False
t=int(input())
for _ in range(t):
    try:
        b=mat_d(list(map(int,input().split())))
    except:
        flag=False
    try:
        if a==b:
            dem+=1
    except:
        flag=False
if flag:
    print(dem)
else:
    print(1)

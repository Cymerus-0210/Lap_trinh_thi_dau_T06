# https://oj.vnoi.info/problem/olp_kc23_beastr

n,q=map(int,input().split())
s=input()
cnt=[[0 for i in range(n+1)] for j in range(26)]

for i in range(len(s)):
    cnt[ord(s[i])-ord('a')][i]=1

for i in range(26):
    for j in range(n):
        cnt[i][j]+=cnt[i][j-1]
# đếm từ 0 đến j thì chữ có mã i xuất hiện bao nhiêu lần và lưu vào cnt
# mã ở đây quy ước 0 là a, 1 là b, 2 là c,...
# ví dụ cnt[3][4] = 3 nghĩa là trong xâu s từ s[0] đến s[4] chữ d xuất hiện 3 lần 
for _ in range(q):
    i,j = map(int,input().split())
    tmp=0
    # đếm từ i đến j có bao nhiêu chứ cái có số lần xuất hiện là lẻ
    for t in range(26):
        if (cnt[t][j]-cnt[t][i-1]) % 2 == 1:
            tmp+=1
    print(tmp//2)
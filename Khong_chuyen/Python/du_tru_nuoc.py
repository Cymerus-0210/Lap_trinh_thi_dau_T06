# https://oj.vnoi.info/problem/olp_kc20_buildcol

n,M = map(int,input().split())
a = [0 for _ in range(n+2)]
b = [0 for _ in range(n+2)]
c = list(map(int,input().split()))


def check(m):
    global n,a,b,M
    con_lai = 0
    # a là độ cao các cột
    # b là lượng nước tối đa mà cột đó có thể chứa được nếu không có cột nào ngoại trừ cột đầu và cột cuối chính là độ cao cột vì 2 ô này không chứa được nước
    # từ đó suy ra b[i] - a[i] sẽ là lượng nước thực tế trong ô thứ i
    for i in range(1,n+1):
        nuoc = b[i]-a[i] #lượng nước ban đầu tại mỗi ô nếu không nâng
        tran_ra = max( 0 , min( m , b[i]) - a[i] )
        # sau khi nâng lên m thì tại ô thứ i tràn ra bao nhiêu nước
        # vì nâng cột lên tối đa là m
        # nếu m nhỏ hơn b[i] mà m - a[i] dương nghĩa là tại a[i] đang thấp hơn m và cần nâng thêm m-a[i] đồng nghĩa với việc tràn ra m-a[i] đơn vị nước
        # nếu m nhỏ hơn b[i] mà m - a[i] không dương nghĩa là tại a[i] đang cao hơn hoặc bằng m nên lượng nước tràn ra là 0
        con_lai += nuoc - tran_ra
        # tính lượng nước còn lại là nước ban đầu trừ nước tràn ra
        if con_lai >= M:
            return True
            # tại một thời điểm bất kỳ mà nước còn lại thoả mãn lớn hơn bằng M thì trả về true ngay lập tức
    return False
    # nếu cộng hết lượng nước còn lại mà không thoả thì trả về false


for i in range(1,n+1):
    a[i]=c[i-1]


tmp = 0
for i in range(1,n+1):
    if tmp < a[i]:
        tmp=a[i]
    b[i]=tmp

tmp=0
for i in range(n,0,-1):
    if tmp < a[i]:
        tmp = a[i]
    b[i] = min(b[i],tmp)

# vì tìm m lớn nhất, nếu m càng tăng thì lượng nước còn lại càng giảm => hàm đơn điệu => tìm kiếm nhị phân binary search
res = -1
mx = max(a[1:n+1])
mn = min(a[1:n+1])
l=mn
r=mx
while l<=r:
    m = (l+r)>>1 # phép toàn bitwise >>1 tương đương với chia 2 lấy phần nguyên
    if check(m):
        res = m
        l = m+1
    else:
        r = m-1
print(res)
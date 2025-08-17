import sys
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
input = sys.stdin.readline


n = int(input())
s = input().strip()

# nếu độ dài xâu là chẵn chứng tỏ là không có kết quả (đề bài)
if n % 2 == 0:
    print("No Solution")
else:
    # cắt xâu thành 2 cặp xâu con
    # so sánh từng ký tự trong 2 cặp xâu đó
    # tìm ra các ký tự khác biệt đó là ký tự bất kỳ cuối cùng trong đề bài
    # nếu có đúng 1 ký tự đó thì có nghĩa là có 1 kết quả duy nhất
    # nếu không tìm ra kết quả đó thì là no sulution
    # nếu có nhiều hơn thì là Multiple
    s1 = s[: len(s) // 2]
    s2 = s[len(s) // 2 :]

    s3 = s[: len(s) // 2 + 1]
    s4 = s[len(s) // 2 + 1 :]
    j = 0
    i = 0
    dem1 = 0
    while i < len(s1) and j < len(s2):
        if s1[i] == s2[j]:
            i += 1
            j += 1
        else:
            j += 1
            dem1 += 1
    j = 0
    i = 0
    dem2 = 0
    while i < len(s4) and j < len(s3):
        if s4[i] == s3[j]:
            i += 1
            j += 1
        else:
            j += 1
            dem2 += 1
    if dem2 < 2 and dem1 < 2:
        if s1 != s4:
            print("Multiple Solutions")
        else:
            print(s1)
    elif dem1 < 2:
        print(s1)
    elif dem2 < 2:
        print(s4)
    else:
        print("No Solution")

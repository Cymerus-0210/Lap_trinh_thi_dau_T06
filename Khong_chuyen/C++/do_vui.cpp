#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    // nếu độ dài xâu là chẵn chứng tỏ là không có kết quả (đề bài)
    if (! n&1) cout << "No Solution";
    else{
        // cắt xâu thành 2 cặp xâu con
        // so sánh từng ký tự trong 2 cặp xâu đó
        // tìm ra các ký tự khác biệt đó là ký tự bất kỳ cuối cùng trong đề bài
        // nếu có đúng 1 ký tự đó thì có nghĩa là có 1 kết quả duy nhất
        // nếu không tìm ra kết quả đó thì là no sulution
        // nếu có nhiều hơn thì là Multiple
        int dem1=0, dem2=0, i=0, j=0;   
        string s1 = s.substr(0, s.size() / 2);
        string s2 = s.substr(s.size() / 2);
        string s3 = s.substr(0, s.size() / 2 + 1);
        string s4 = s.substr(s.size() / 2 + 1);
        while (i < s1.size() and j < s2.size()){
            if (s1[i]==s2[j]){
                i++;
                j++;
            }
            else {
                j++;
                dem1++;
            }
        }
        j=0;
        i=0;
        while (i < s4.size() and j < s3.size()){
            if (s4[i]==s3[j]){
                i++;
                j++;
            }
            else {
                j++;
                dem2++;
            }
        }
        if (dem2<2 and dem1<2)
            if (s1 != s4)
                cout << "Multiple Solutions\n";
            else 
                cout << s1 << endl;
        else if (dem1<2)
            cout << s1 << endl;
        else if (dem2<2)
            cout << s4 << endl;
        else 
            cout << "No Solution\n";
    }
    return 0;
}
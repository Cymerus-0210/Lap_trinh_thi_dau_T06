// https://oj.vnoi.info/problem/olp_kc22_noelgift

#include<bits/stdc++.h>
using namespace std;
// ý tưởng của bài này là xem 1 món quà là 1 điểm trong đồ thì
// 1 bé là 1 cạnh trong đồ thị
// như thế thì mỗi bé sẽ nối với 2 món quà
// sau khi xây dựng đồ thì sẽ tìm xem có cách nào để chia cắt đồ thị ra thành nhiều phần trong đó số đỉnh vẫn còn được nối với cạnh là nhiều nhất


vector <int> qua[100005]; 
// mảng này lưu các đỉnh của đồ thị tương đương với các món quà 
// ví dụ vị trí qua[1] = [2, 4, 3] thì có nghĩa là món quà số 1 có 3 bé thích trong đó nó sẽ được ghép cặp với các món quà số 2, 4, 3

int n, m; 
int be[100005];
// đây là số bậc của đồ thị tương ứng với các cạnh và tương ứng với số các bé trong đề bài 
// ví dụ be[1] = 3 đồng nghĩa với việc có 3 bé thích món quà số 1
bool visited[100005];  
// mảng visited để thực thi thuật toán dfs
int ans = 0; 
int so_be = 0; 
int so_mon_qua = 0; 
// hàm dfs dùng để tìm ra thứ tự phát các món quà tối ưu
void dfs(int u) {
  so_be += be[u];
  so_mon_qua++; 
  visited[u] = true;
  for (int i = 0; i < (int) qua[u].size(); i++) {
    int v = qua[u][i];
    if (visited[v] == false) {
      dfs(v); 
    }
  }
}

int main () {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    qua[u].push_back(v);
    qua[v].push_back(u);
    be[u]++;
    be[v]++; 
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      so_be = 0; 
      so_mon_qua = 0;
      dfs(i);
      ans += min(so_mon_qua, so_be / 2); 
        // nếu có nhiều quà hơn số bé thì cũng chỉ phát được cho từng đó bé
        // nếu có nhiều bé hơn quà thì cũng chỉ phát được từng đó quà
        // nên lấy min của 2 giá trị 
    }   
  }
  cout << ans;
  return 0; 
}

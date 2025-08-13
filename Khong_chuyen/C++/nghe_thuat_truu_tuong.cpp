// https://oj.vnoi.info/problem/olp_kc22_abstract

#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  int a[n][m],mark[n][m];
  for (auto &x:a)
    for (auto &y:x)
        cin >>y;
  for (auto &x:mark)
    for (auto &y:x)
      y=0;
  for (int i=0;i<n;i++)
  {
    if (a[i][0]>0)
    mark[i][0]=1;
    if (a[i][m-1]>0)
    mark[i][m-1]=1;
  }
  for (int j=0 ; j<m ; j++)
  {
    if(a[0][j]>0)
    mark[0][j]=1;
    if(a[n-1][j]>0)
    mark[n-1][j]=1;
  }

  for (int i=0 ; i<n ; i++)
  {
    int max=a[i][0];
    for (int j=0; j<m ; j++)
      if (a[i][j]>max)
      {
        max=a[i][j];
        mark[i][j]=1;
      }
  }
  for (int i=0 ; i<n ; i++)
  {
    int max=a[i][m-1];
    for (int j=m-1; j>=0 ; j--)
      if (a[i][j]>max)
      {
        max=a[i][j];
        mark[i][j]=1;
      }
  }

  for (int j=0 ; j<m ; j++)
  {
    int max=a[0][j];
    for (int i=0; i<n ; i++)
      if (a[i][j]>max)
      {
        max=a[i][j];
        mark[i][j]=1;
      }
  }
  for (int j=0 ; j<m ; j++)
  {
    int max=a[n-1][j];
    for (int i=n-1; i>=0 ; i--)
      if (a[i][j]>max)
      {
        max=a[i][j];
        mark[i][j]=1;
      }
  }

  int res=0;
  for (auto &x:mark)
    for (auto &y:x)
      if (y==1)
        res++;
  cout << res;

  return 0;
}

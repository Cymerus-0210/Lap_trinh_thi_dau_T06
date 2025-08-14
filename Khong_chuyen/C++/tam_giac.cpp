// https://oj.vnoi.info/problem/olp_kc19_tri

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    int d[n];

    for (int i = 0; i < n; i++) cin >> d[i];

    int count = 0;
    int maxk = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (i < k) {
            if (d[i] > maxk) {
                sum += maxk;
                if (d[i] != 0) {
                    maxk = d[i];
                }
            } else {
                sum += d[i];
            }
            if (i == k - 1) { 
                if (sum > maxk) {
                    count++;
                }
            }
        } else {
            if (maxk == d[i - k]) {
                sum += d[i];
                maxk = *max_element(d + (i - k + 1), d + (i + 1)); 
                sum -= maxk;
            } else {
                sum -= d[i - k];
                if (d[i] > maxk) {
                    sum += maxk;
                    maxk = d[i];
                } else {
                    sum += d[i];
                }
            }

            if (sum > maxk) {
                count++;
            }
        }
    }

    cout << count;



    return 0;
}
#include <bits/stdc++.h>
using namespace std;

inline long long mod_norm(__int128 x, long long S) {
    __int128 r = x % S;
    if (r < 0) r += S;
    return (long long)r;
}

const int MAXK = 500;     // tối đa số ma trận
const int MAXN = 100;    // tối đa kích thước ma trận

__int128 matrices[MAXK][MAXN][MAXN];
long long mat_h[MAXN];
long long res[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, n, hang, cot, S;
    cin >> k >> n >> hang >> cot >> S;
    for (long long i = 0; i < k; ++i)
        for (long long r = 0; r < n; ++r)
            for (long long c = 0; c < n; ++c) {
                long long x;
                cin >> x;
                matrices[i][r][c] = (__int128)x;
            }

    --hang; --cot;

    // Lấy hàng hang của ma trận đầu
    for (long long i = 0; i < n; ++i)
        mat_h[i] = (long long)(matrices[0][hang][i] % S);

    // Nhân tuần tự các ma trận
    for (long long i = 1; i < k; ++i) {
        fill(res, res + n, 0);
        for (long long c = 0; c < n; ++c) {
            __int128 acc = 0;
            for (long long h = 0; h < n; ++h) {
                __int128 val = matrices[i][h][c] * mat_h[h];
                val = val % S;
                if (val < 0) val += S;
                acc += val;
            }
            res[c] = (long long)(acc % S);
        }
        for (long long j = 0; j < n; ++j)
            mat_h[j] = res[j];
    }

    cout << mat_h[cot] << "\n";

    return 0;
}

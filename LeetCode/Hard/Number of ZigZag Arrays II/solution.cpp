class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;
    using Matrix = vector<vector<ll>>;
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size(), m = B[0].size(), p = B.size();
        Matrix C(n, vector<ll>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < m; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;
        Matrix state(sz, vector<ll>(1, 0));
        for (int v = 1; v <= m; v++) {
            state[v - 1][0] = v - 1;
            state[m + v - 1][0] = m - v;
        }
        Matrix trans(sz, vector<ll>(sz, 0));
        for (int v = 1; v <= m; v++) {
            for (int u = 1; u < v; u++) {
                trans[v - 1][m + u - 1] = 1;
            }
        }
        for (int v = 1; v <= m; v++) {
            for (int u = v + 1; u <= m; u++) {
                trans[m + v - 1][u - 1] = 1;
            }
        }
        Matrix finalState = multiply(power(trans, n - 2), state);
        ll ans = 0;
        for (int i = 0; i < sz; i++) {
            ans = (ans + finalState[i][0]) % MOD;
        }
        return ans;
    }
};
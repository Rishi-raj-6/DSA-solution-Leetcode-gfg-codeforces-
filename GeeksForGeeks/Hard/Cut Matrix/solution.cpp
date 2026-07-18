class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        const long long MOD = 1000000007;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<char>> rowSuffixHasOne(n, vector<char>(m + 1, 0));
        for (int a = 0; a < n; a++) {
            rowSuffixHasOne[a][m] = 0;
            for (int c = m - 1; c >= 0; c--) {
                rowSuffixHasOne[a][c] = matrix[a][c] || rowSuffixHasOne[a][c + 1];
            }
        }

        vector<vector<char>> colSuffixHasOne(m, vector<char>(n + 1, 0));
        for (int b = 0; b < m; b++) {
            colSuffixHasOne[b][n] = 0;
            for (int r = n - 1; r >= 0; r--) {
                colSuffixHasOne[b][r] = matrix[r][b] || colSuffixHasOne[b][r + 1];
            }
        }

        vector<vector<int>> firstRowWithOne(n + 1, vector<int>(m, n));
        for (int c = 0; c < m; c++) firstRowWithOne[n][c] = n;
        for (int r = n - 1; r >= 0; r--) {
            for (int c = 0; c < m; c++) {
                firstRowWithOne[r][c] = rowSuffixHasOne[r][c] ? r : firstRowWithOne[r + 1][c];
            }
        }

        vector<vector<int>> firstColWithOne(m + 1, vector<int>(n, m));
        for (int r = 0; r < n; r++) firstColWithOne[m][r] = m;
        for (int c = m - 1; c >= 0; c--) {
            for (int r = 0; r < n; r++) {
                firstColWithOne[c][r] = colSuffixHasOne[c][r] ? c : firstColWithOne[c + 1][r];
            }
        }

        vector<vector<long long>> fprev(n, vector<long long>(m, 0));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                fprev[r][c] = (firstRowWithOne[r][c] < n) ? 1 : 0;
            }
        }

        if (k == 1) {
            return (int)(fprev[0][0] % MOD);
        }

        for (int p = 2; p <= k; p++) {
            vector<vector<long long>> SS(m, vector<long long>(n + 1, 0));
            for (int c = 0; c < m; c++) {
                SS[c][n] = 0;
                for (int x = n - 1; x >= 0; x--) {
                    SS[c][x] = (SS[c][x + 1] + fprev[x][c]) % MOD;
                }
            }

            vector<vector<long long>> SR(n, vector<long long>(m + 1, 0));
            for (int r = 0; r < n; r++) {
                SR[r][m] = 0;
                for (int x = m - 1; x >= 0; x--) {
                    SR[r][x] = (SR[r][x + 1] + fprev[r][x]) % MOD;
                }
            }

            vector<vector<long long>> fcur(n, vector<long long>(m, 0));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    long long hsum = 0;
                    int t = firstRowWithOne[r][c];
                    if (t < n) hsum = SS[c][t + 1];

                    long long vsum = 0;
                    int s = firstColWithOne[c][r];
                    if (s < m) vsum = SR[r][s + 1];

                    fcur[r][c] = (hsum + vsum) % MOD;
                }
            }

            fprev = fcur;
        }

        return (int)(fprev[0][0] % MOD);
    }
};
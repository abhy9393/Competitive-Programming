#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // Step 1: find minimum number of columns (k) that must output '1'
        int diff = x - n;
        int k = (diff <= 0) ? 0 : (diff + 1) / 2;

        // Step 2: figure out extra ones to distribute
        int extra = x - 2 * k;        // leftover ones after giving 2 to each '1'-column
        int zeroCols = n - k;         // number of '0'-output columns

        int extraForZeroCols = min(extra, zeroCols); // give 1 extra to some zero-cols
        int extraForOneCols = extra - extraForZeroCols; // rest goes to one-cols

        string ans(3 * n, '0'); // build final string, all zero initially

        // Fill zero-output columns (first 'zeroCols' columns)
        for (int i = 0; i < zeroCols; i++) {
            int onesHere = (i < extraForZeroCols) ? 1 : 0; // 0 or 1 ones in this column
            for (int j = 0; j < onesHere; j++) {
                ans[i + j * n] = '1';
            }
        }

        // Fill one-output columns (last 'k' columns)
        for (int idx = 0; idx < k; idx++) {
            int col = zeroCols + idx;
            int onesHere = (idx < extraForOneCols) ? 3 : 2; // 2 or 3 ones in this column
            for (int j = 0; j < onesHere; j++) {
                ans[col + j * n] = '1';
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
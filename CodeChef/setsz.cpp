// step-1  remove duplicates from the array because its generate same sum for queries
// step-2   mnanage overlapping intervals ex-2 4 5 7  X=6 then [3 8] and for 4 [5 10] here we see ans onlye [3 10] means min(4-2,x)  this value only add in ths interval
// step-3    we calculate all gaps ands store it in gap array and sort them because using binary seach we want to find just greater element of x because then x elemnt  is always add  and before it add all small element asprefix sum; 
    // vector<long long> pref(gaps.size() + 1, 0);
    // for (int i = 0; i < (int)gaps.size(); i++) {
    //     pref[i + 1] = pref[i] + gaps[i];
    // }

// Time complexcity =O((N+Q)logN)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    int M = (int)A.size();

    vector<long long> gaps;
    for (int i = 0; i + 1 < M; i++) {
        gaps.push_back(A[i + 1] - A[i]);
    }

    sort(gaps.begin(), gaps.end());

    vector<long long> pref(gaps.size() + 1, 0);
    for (int i = 0; i < (int)gaps.size(); i++) {
        pref[i + 1] = pref[i] + gaps[i];
    }

    while (Q--) {
        long long X;
        cin >> X;

        int k = upper_bound(gaps.begin(), gaps.end(), X) - gaps.begin();

        long long ans = pref[k] + 1LL * (M - k) * X;

        cout << ans << '\n';
    }

    return 0;
}
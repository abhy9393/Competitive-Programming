#include <bits/stdc++.h>
using namespace std;
//  logic: phle without changing ke shrink kro fir changing krke reduce kro
int main() {
    int t;
    cin>>t;
 
    while(t--) {
        int n;
            cin>> n;
        string s;
        cin>>s;
 
        int cnt=1;
        for (int i= 1; i<n; i++) {
            if(s[i]!=s[i-1])
                cnt++;
        }
 
        int ans=cnt;
 
        for (int i=1; i<n-1;i++) {
 
int reduction=0;
 
if (s[i]!= s[i-1] && s[i] != s[i+1]) {
 
    if (s[i-1] == s[i+1])
        reduction= 2;
    else
        reduction=1;
}
ans = min(ans,cnt-reduction);
        }
 
        cout <<ans<< "\n";
    }
 
    return 0;
}
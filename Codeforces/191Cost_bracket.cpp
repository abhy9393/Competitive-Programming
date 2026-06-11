#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
string ans(n,'0');
         stack<int>st;
        vector<pair<int,int>>vec;
         for(int i=0;i<n;i++){
            if(str[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    int temp=st.top();
                    vec.push_back({temp,i});
                    st.pop();
                }
            }
         }
         int pivot=n+1;
         while(!st.empty()){
            pivot=st.top();
            st.pop();
         }
         for(auto it:vec){
            int left=it.first;
            int right=it.second;
            if(left<pivot&&k>0){
                 ans[left]='1';
                 k--;
            }
            else if(right>pivot&&k>0){
                ans[right]='1';
                k--;
            }
           
         }


        
        cout << ans << "\n";
    }
    return 0;
}

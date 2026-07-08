/*
Problem : Equal Elements
Platform : CodeChef
Difficulty : 1738

Approach :
- Greedy + Map
- Traverse from right to left.

Observation :
- Left se future decisions lene padte hain.
- Right se last pair ko fix kar sakte hain.
- Pair milte hi mp.clear().

Time : O(N log N)
Space : O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vector<int>arr(n+1);
       unordered_map<int,int>mpp;
       for(int i=1;i<=n;i++){
           cin>>arr[i];

       }
      int ans=0;
      mpp[arr[n]]++;
      for(int i=n-1;i>=1;i--){
          if(mpp[arr[i]]==1){  //means same elemnt second baar aaya jo phle freq 1 kr chuka th means pair complete
             ans+=2;
             mpp.clear();
             continue;
          }
          mpp[arr[i]]++;
      }
      cout<<ans<<endl; 
   }
}

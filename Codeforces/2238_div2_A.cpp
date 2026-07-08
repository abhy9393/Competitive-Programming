
// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding sorting space)


// thinking step-1 phle sum chek kr lo agar sum hi kam hi a ka to fir possible hi nhi subtraction
// step-2 ek baar without reorder nikal lo ek baar oder krke nikal lo 
// step 3 dono me minimum jisme ho whi ans
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int>a(n);
        vector<int>b(n);
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum1+=a[i];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
            sum2+=b[j];
        }
        if(sum1<sum2){
            cout<<-1<<"\n";
        }
        else{
            
            int count=0;
            int count1=0;
            bool ok=true;
            bool flag=true;
           for(int i=0;i<n;i++){
            if(a[i]<b[i]){
                ok=false;
                break;
            }
            else{
            count+=(a[i]-b[i]);
            }
           }  
           sort(a.begin(),a.end());
           sort(b.begin(),b.end());
for(int i=0;i<n;i++){
            if(a[i]<b[i]){
                flag=false;
                break;
            }
            else{
            count1+=(a[i]-b[i]);
            }
           }  

          if(!ok && !flag){
  cout<<-1<<"\n";
          } 
          else if(ok&&flag){
    cout<<min(count,c+count1)<<"\n";
          }
          else if(!ok&&flag){
            cout<<(c+count1)<<"\n";
          }
          else cout<<count<<"\n";
        }
          
    }
    return 0;
}
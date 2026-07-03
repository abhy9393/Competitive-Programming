#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1);
        vector<int>b(n+1);
      for(int i=1;i<=n;i++)
    cin >> a[i];

for(int i=1;i<=n;i++)
    cin >> b[i];
long long  lev=0;
bool ok=true;
for(int i=1;i<=n;i++){
    // case 1 if ai needs incement then gain levaearge
    if(a[i]<=b[i]){
        lev+=(long long)(b[i]-a[i]);
    }

    else{
        int diff=a[i]-b[i];
        if(lev>=diff){
            lev-=diff;
        }
        else{
ok=false;
break;
        }
    }

}
if(ok){
 cout<<"yes"<<"\n";
}
else cout<<"no"<<"\n";
    }
    return 0;
}
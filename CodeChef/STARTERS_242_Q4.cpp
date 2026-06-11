#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    int n,k;
    cin>>n>>k;
    // we create a vector array of size n+1 by storing from 1
    vector<int>arr(n+1,0);  //we initilize with 0 because according to indexces we add that card score
   bool flag =true;
   int card=k;
   while(card){
// first condition 1st person take maximum value score card
if(flag){
    for(int i=1;i<=n&&card;i++){ //ex-n=3,k=7  p1->7 p2->6 p3->5 card=4
    arr[i]+=card;
    card--;
    }
}
// second when last person take maximum card score
else{
 for(int i=n;i>=1&&card;i--){  //p3->5+4 p2->6+3 p3->7+2
    arr[i]+=card;
    card--;
 }
}
flag=!flag; //always do this 
   }
  cout<<*max_element(arr.begin(),arr.end())<<"\n";
   }
    return 0;
}
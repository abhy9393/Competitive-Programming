class Solution {
public:
    string minWindow(string s, string t) {
      vector<int>hash(256,0);
    for(int i=0;i<t.size();i++){
        hash[t[i]]++;
    }
    int count=0; //its count the length of t 
    int n=s.size();
    int minlen=INT_MAX;
  int sidx=-1;
  int l=0,r=0;
  int m=t.size();
  while(r<n){
    if(hash[s[r]]>0){

     count++;
    }
     hash[s[r]]--;  //decrement always 
    while(count==m){
        if(r-l+1<minlen){
            minlen=r-l+1;
            sidx=l;
        }
        hash[s[l]]++;
        if(hash[s[l]]>0){
            count--;
        }
        l++;
    }
  r++;

  }


  return sidx==-1?"":s.substr(sidx,minlen);
    }
};
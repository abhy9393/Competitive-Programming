class Solution {
public:

int solve(string &s,int l,int r,int k){  //always use &s not copy
if(l>r) return 0; //abb maan lo a pe hi k se kam ho gya to left ke liye r=i-1 to -1 invalid ho jaega 

vector<int>freq(26,0);

for(int i=l;i<=r;i++){
    freq[s[i]-'a']++;
}
 for(int i=l;i<=r;i++){

    if(freq[s[i]-'a']<k){
        int left=solve(s,l,i-1,k); //use i not l knuki jis i per break hoga lekin starting ke liye l use krna knuki maan lo tum mid ke right me ho wha khi break mila to 0 se left thodi start hoga
        int right=solve(s,i+1,r,k);
    return max(left,right); //dono taraf me se jidhar maximum ho
    }
 }

 return r-l+1; //agar sbka hi freq>=k ho to pura length hi ans
}

    int longestSubstring(string s, int k) {
// thought that ki jis char ki freq pure string me <k ho to uske left aur right chek kro unme jisme max len ho wo lao aese baar babar recursive call kro agr koi na mile aea jiske freq lesss ho k se to r-l+1 puri length return kr do

  if(s.size()<k) return 0;
 return  solve(s,0,s.size()-1,k);


    }
};
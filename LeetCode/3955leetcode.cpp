class Solution {
public:

 void calculate(int n,int k,int idx, int cost,bool prevones, string str,vector<string> &ans){
    if(cost>k) return;
    if(idx==n){
        ans.push_back(str);
        return;
    }
     str.push_back('0');
     calculate(n,k,idx+1,cost,false,str,ans);
     str.pop_back();

     if(!prevones){
        str.push_back('1');
        calculate(n,k,idx+1,cost+idx,true,str,ans);
        str.pop_back();
     } 

 }

    vector<string> generateValidStrings(int n, int k) {
  vector<string> ans;
  string str;
//   bool prevones;
   calculate(n,k,0,0,false,str,ans);

  return ans;

    }
};
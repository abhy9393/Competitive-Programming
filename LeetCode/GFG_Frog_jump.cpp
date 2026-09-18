


class Solution {
  public:
//   int func(int idx,vector<int>& height, vector<int>&dp){
//     //   T.C=O(N) S.C=(N)+O(N) isme ek recursion stack space hi isko remove krnege tabulation method s e
//     if(idx==0) return 0;
//      if(dp[idx]!=-1) return dp[idx];
//     int left=func(idx-1,height,dp)+abs(height[idx]-height[idx-1]);// ex- 20 30 15 aap 15 per ho to 30 per ja rh to 15 air 30 ka abs diff
//     int right=INT_MAX;
// if(idx>1){
//      right=func(idx-2,height,dp)+abs(height[idx]-height[idx-2]);
// }
//  return dp[idx]=min(left,right);
//   }
  
    int minCost(vector<int>& height) {
        // Code here
        // int n=height.size();
        // vector<int>dp(n+1,-1);
        //  return func( n-1,height,dp);
        
        // using tabulation method
        // step-1 see base case and set that value in dp
        // step-2 running for loop after this and take dp help yha jo kaam fun krta th wo dp[odx] kregw
       int n=height.size();
        vector<int>dp(n,0);
        // dp[0]=0;
        int prev,prev2=0;
        for(int i=1;i<n;i++){
            // int fs=dp[i-1]+abs(height[i]-height[i-1]);
            int fs=prev+abs(height[i]-height[i-1]);
            int ss=INT_MAX;
            
            if(i>1){
                // ss=dp[i-2]+abs(height[i]-height[i-2]);
                ss=prev2+abs(height[i]-height[i-2]);
            }
           
            //  dp[i]=min(fs,ss);
            int curr=min(fs,ss);
            prev2=prev;
            prev=curr;
        }
        // return dp[n-1];
        return prev;
    }
};

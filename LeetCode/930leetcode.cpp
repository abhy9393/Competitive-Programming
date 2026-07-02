class Solution {
public:

  int countsubarr(vector<int>& arr, int goal){
    if(goal<0) return 0;
int count=0;
int l=0,r=0;
  int sum=0;

  int n=arr.size();
while(r<n){
    sum+=arr[r];
    while(sum>goal){
        sum=sum-arr[l];
        l++;
    }
    
// All subarrays ending at 'r' and starting from l...r are valid. r-l+1  ex- 101 count=1+2+3 which is size

     count+=(r-l+1);
    
     r++;

    }
return count;
}

  
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     To get the number of subarrays with sum exactly equal to goal:
    //   Exactly(goal) = AtMost(goal) - AtMost(goal - 1)   
    // exactle sum k = atmost(<=k)-atmost(<=k-1) 

         int total=countsubarr(nums,goal)-countsubarr(nums,goal-1);
         return total;
    }
};
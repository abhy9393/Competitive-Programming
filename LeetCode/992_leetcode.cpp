class Solution {
public:
     int subarrays(vector<int>& arr,int k){
          int n=arr.size();
        vector<int>freq(n+1,0);//given in question till n then use n+1
       int l=0,r=0;
       int count=0;
       int dist=0;
       while(r<n){
        freq[arr[r]]++;
        if(freq[arr[r]]==1) dist++;   //yadi kisi elemnet ki freq 1 aai to wo distinct me count hone layak hi 
        while(dist>k){  
                freq[arr[l]]--;  
            if(freq[arr[l]]==0){  //ex 5 ki freq 3 hi aur 2 ki 1 hi aur 1 ki 1 hi to phle jjb tk 5 ki kul freq 0 nhi ho jati dist ki value kam nhi higi 
            dist--;
            }
                l++;
        }
        
        count+=(r-l+1);  //count total subarryas
        r++;
       }
       return count;
     }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     int n=nums.size();
         
         int total= subarrays(nums,k)-subarrays(nums,k-1);  // concept of atmost k- atmost(k-1)
         return total;
    }
};
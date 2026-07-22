class Solution {
  public:
    //   static bool cmp(pair<int,int>a,pair<int,int>b){
            
    //         return ((double)a.first/a.second>(double)b.first/b.second);
    //       }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here

        // here we enter valu and weight for sorting 
        vector<pair<int,int>>arr;
        for(int i=0;i<val.size();i++){
            arr.push_back({val[i],wt[i]});
        }
       
            //   sort(arr.begin(),arr.end(),cmp);
            // OR
             //here we sort according to maximumm fraction value of val/weight jiska jada hoga usi ka use krenge
            sort(arr.begin(),arr.end(),[]
                (pair<int,int>a,pair<int,int>b){
                    return  ((double)a.first/a.second>(double)b.first/b.second);
                }
            );
        double res=0;
         for(auto it:arr){
             if(capacity>=it.second){  //total capacity ko hmesa weight se compare krenge aagr capacity jada hi to pur value add kr do 
                // aur fir capacity se utna weight minus kr do aur res me uski value ad kr do
                 capacity-=it.second;
                 res+=it.first;
             }
             else if(capacity!=0&&capacity<it.second){  //jb capacity kam pad jae to fraction nikal lo 
                  double num=(double)it.first/it.second;
                  res+=(num*capacity);
                  break;
             }
          
         }
         return res;
        
    }
};

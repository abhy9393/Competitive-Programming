class Solution {
public:
typedef pair<int,int>p;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
          vector<int>result;
          vector<array<int,3>>arr;

        //   push these three entries
         for(int i=0;i<n;i++){
         int start_time=tasks[i][0];
         int end_time=tasks[i][1];
            arr.push_back({start_time,end_time,i});
         }
    //  sort according to start time
    sort(arr.begin(),arr.end());
// declare min heap pq for storing end time and index after comparing start time with current time

 priority_queue<p,vector<p>,greater<p>>pq;
    
    long long currtime=0;
   
      int idx=0;
    
      while(idx<n||!pq.empty()){
if (pq.empty()&&currtime<arr[idx][0]) { //isko yha isiliye kiya knuki ho ske ki isse aage koi possible hi na ho aur aage pq empty se pop hoone lge
    currtime = arr[idx][0];
    
}
       while(idx<n&&currtime>=arr[idx][0]){  // compare till this condition possible
        pq.push({arr[idx][1],arr[idx][2]}); //array se index ko push
        idx++;
       }
       auto it=pq.top();
       pq.pop();
       currtime+=it.first;
       result.push_back(it.second);
      }

return result;
    }
};
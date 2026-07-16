class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

// //         Time Complexity: O(N)
// // Space Complexity: O(1)
//        vector<int>freq(26,0);
//        int mxfreq=0;
// for (char ch : tasks) {
//     freq[ch - 'A']++;
//     mxfreq = max(mxfreq, freq[ch - 'A']);
// }
// int cnt = 0;
// for (int x : freq) {
//     if (x == mxfreq)
//         cnt++;
// }
//     int frame= (n+1)*(mxfreq-1)+cnt;
//     //  return fmax(tasks.size(),frame);
//     // or
//      return max((int)tasks.size(),frame);

// using heap

// Time Complexity: O(N)
priority_queue<int>pq; 

 vector<int>mpp(26,0);
 for(char ch:tasks){
    mpp[ch-'A']++;
 }
 for (int it : mpp) {
    if (it > 0)
        pq.push(it);
}
int time=0;
  while(!pq.empty()){

    vector<int>temp;
    for(int i=1;i<=n+1;i++){
        if(!pq.empty()){
        int freq=pq.top();
        pq.pop();
        freq--;
        temp.push_back(freq);
    }
  }
   for(int f:temp){
    if(f>0){
     pq.push(f);
    }
   }
    if(pq.empty()){
        time+=temp.size();
    }
    else{
        time+=n+1;
    }
  }
return time;
    }
};
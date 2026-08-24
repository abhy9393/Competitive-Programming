class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return 0;
      int ans=1; //for beginword
      int n=wordList.size();
      queue<string>q;
      vector<int>vis(n,0);
      q.push(beginWord);

      while(!q.empty()){
        // ans++; yha ans nhi likhenge knuki ye visited ke baad agar pop hua to bhi increase kr lega
        
        int size=q.size();
        while(size--){
        string s=q.front();
        q.pop();
       for(int i=0;i<n;i++){
        string currstr=wordList[i];
        int cnt=0;
       for(int j=0;j<currstr.size();j++){
        if(s[j]!=currstr[j]){
cnt++;
        }

       }
       if(cnt==1&&vis[i]!=1){ 
      
            if(currstr==endWord){  //milte hi stop kr do q ke empty ka wait nhi knuki hme path yhi se mil gya 
       return ans+1;
     
        
       }
    
        q.push(currstr);
        vis[i]=1;
       }
   
       } 
   
      } 
      ans++; //isko har level  ke khatam hone ke baad incease krenge 
      }
      return 0;  //maan lo ki endword se common mila hi nhi to cnt kbhi 1 hoga hi nhi ex- beginWord = "hot" endWord   = "dog" wordList  = ["hot", "dog"] to ab direct 0 hi hoga knuki koi commo nhi 
    }
};
class Solution {
  public:
    vector<vector<string>> findSequences(vector<string> &words, string &s, string &e) {
        // code here
         vector<vector<string>>ans;
         
         unordered_set<string>st(words.begin(),words.end());
        //  variable size queue 
        queue<vector<string>>q;
        q.push({s});
        // usedlevel jo uss level per use hue unhe delte krne ke lye
        vector<string>usedonlevel;
        usedonlevel.push_back(s);
        st.erase(s); //iss level per ye use ho chuka to delete kr do ab future me use kbhi nhi ho skta
      int  level=0; //jb queue empty hi
        
        while(!q.empty()){
            vector<string>vec=q.front();
            q.pop();
           if(vec.size()>level){ //level tbhi increase kro jb vec ki size bade knuki same level per size same hoti hi to hmesa level++ nhi kr skte
               
           level++;
            for(auto it:usedonlevel){
                st.erase(it);
            }
            usedonlevel.clear();
           }
            
            string endword=vec.back(); //last word nikal liya
            //ab matching chek kre
            if(endword==e){
                ans.push_back(vec);
                continue;
            }
            for(int i=0;i<endword.size();i++){
              char  original=endword[i];
              for(char ch='a';ch<='z';ch++){
                  endword[i]=ch;
                  if(st.count(endword)){
                    // jb first match mila usko vec me push krke fir q me push kr denge aur us particular word ko usedonlevel per bhi push kr denge taki delete kr pye fir pop kr lenge vec se knuki aur iske baad jo matching word milenge unko bhi same level pr push krna hi
                    vec.push_back(endword);
                    q.push(vec);
                    usedonlevel.push_back(endword);
                    vec.pop_back();
                    
                  }
              }
              endword[i]=original;
            }
            
            
            
        }
        
        return ans;
        
        
    }
};


  class disjoint{
    vector<int>rank,parent;
public:
      disjoint(int n){
      rank.resize(n+1,0); //for one based indeexing 
parent.resize(n+1);
    for(int i=1;i<=n;i++){  //initalize parent with self
        parent[i]=i;
    }
}
    //   function for finding ultimate parent
    int findUparent(int node){
       if(node==parent[node]) return node;
 
 return parent[node]=findUparent(parent[node]);

    }
 
    // function for union rank 

     void UnionByrnak(int u,int v){  //2 value diye honge inhi ke beech edge add krna hota hi
      int ul_u=findUparent(u); //ultimate parent of u
      int ul_v=findUparent(v);

      if(ul_u==ul_v) return; //if both has same component 

      else if(rank[ul_u]<rank[ul_v]){ //maan ultimate parent of u ka rank les hi v ke then connect smaller rank with higer rank and smaller ka parent longer and longer ka rank not increse by one because rank same nhi tha to direct ultimate parent se hi connect hoga jisme alredy kuch connected hi 
          parent[ul_u]=ul_v;
          
      }
      else if(rank[ul_v]<rank[ul_u]){ //maan ultimate parent of u ka rank les hi v ke then connect smaller rank with higer rank and smaller ka parent longer and longer ka rank not increse by one because rank same nhi tha to direct ultimate parent se hi connect hoga jisme alredy kuch connected hi 
          parent[ul_v]=ul_u;
          
      }
      else{ //if both parent has equal rank then kisi ka bhi rank one se increse kr do bs jiska increase krna usko parent bna dena
        parent[ul_u]=ul_v;
        rank[ul_v]++;

      }

     

      }




  };


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();

        disjoint ds(n);
        // step-1 mapping mail only with nodes jo jisme belong kr rha ho use mapp kr do jase ex- johnsmith@mail.com","john_newyork@mail->0 ye name wale sare mail iss 0 node me belong krenge
        unordered_map<string,int>mapedMail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){ //take only mails not name
                string mail=accounts[i][j];
             if(mapedMail.find(mail)==mapedMail.end()){ //maan lo koi mail aesa hi jo phle se kisi node me nhi belong kr rh then 
               mapedMail[mail]=i;//uske hi ith node me mapped krdo

             }
             else{ //maaan lo koi mail phle se mapped hi fir se aa gya to wo mail khi fir se nhi push krna hi bs jiss node me ye mail th usko connect kr do jisse match kia hi taki in future hum iss mail ke jo remaining mail hi unko iske merged wale nide me be paye.knuki hum sare remaining mail ko unke node ke ultimste parent per hi bjenege 
             ds.UnionByrnak(i,mapedMail[mail]); 

             }
            }
        }

        // step-2 push all related mail in their ultimate parent and create list
        vector<string>mergedMail[n]; //  vector<vector<string>>mergedMail(n) same hi dono () []
     
             for(auto it:mapedMail){
                string mail=it.first;
                int node= ds.findUparent(it.second);
                 mergedMail[node].push_back(mail);
             }
        
        // step-3 pick up the name and after sorting all mails list direct push in the new temp arrray where temp[0] already name and yadi kisi i wlaw per koi mail nhi hoga to usko skip krna ex- 3 per aesa mail rh ho jo phle kisi me belong kiua ho to isme koi aur remaining nhi rheg
  vector<vector<string>>ans;
  for(int i=0;i<n;i++){
     if(mergedMail[i].size()==0) continue;
     sort(mergedMail[i].begin(),mergedMail[i].end());
     vector<string>temp;
    temp.push_back(accounts[i][0]); //push name first
    for(auto it:mergedMail[i]){ //particular list ke ek ek mail per jao
        temp.push_back(it);
    }
ans.push_back(temp);
  }
 return ans;
    }
};
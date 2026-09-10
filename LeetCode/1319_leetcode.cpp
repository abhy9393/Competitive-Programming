class Solution {
  vector<int>rank,parent;
public:
      int findUparent(int node){
           if(node==parent[node]) return node;
           return parent[node]=findUparent(parent[node]);
      }

    void UnionByrank(int u,int v){  //ye bs connection stablize krta iske call se 
      int ul_u=findUparent(u);
      int ul_v=findUparent(v);
      if(ul_u==ul_v) return; //return original function
      else if(rank[ul_u]<rank[ul_v]){  //isme rank plus nhi krni hoti knu less rank wala direct parent se connect hota hi already uss level per aur bhi component hote hi 
        parent[ul_u]=ul_v;
      }
      else if(rank[ul_v]<rank[ul_u]){
        parent[ul_v]=ul_u;
      }
    else{
        parent[ul_u]=ul_v; //yha ek ki rank increase krni hoti hi knuki dono same rank hi to ek to down jana hoga 
        rank[ul_v]++; 
    }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
           rank.resize(n,0);
           parent.resize(n);

              for(int i=0;i<n;i++){
                parent[i]=i;
              }
              int extra=0;
              int components=n; //assume initially are  single node so n components
     for(auto it:connections){
        int u=it[0];
        int v=it[1];
      if(findUparent(u)==findUparent(v)){ //mtlb in dono ke beech edge exist kr rh aur dono same parent se conected hi mtlb ek extra edge rkhe hi 
      extra++;

      }
      else{
        UnionByrank(u,v);//iss call se edge connect ho jate hi to mtlb me se ek component kam ho gya
        components--;
      }

     }
     if(extra>=components-1) return components-1;  //maan lo 4 extra hi aur 5 component hi to connection ke liye 4 hi chiye na agar 7 bhi hota extra to bhi hme need to 4 ki hi na minimum 

 return -1;
    }
};
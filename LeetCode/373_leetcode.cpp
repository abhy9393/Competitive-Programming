class Solution {
public:

typedef pair<int,pair<int,int>>p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
          int n=nums1.size();
          int m=nums2.size();
            priority_queue<p,vector<p>,greater<p>>pq;

            // step-1 find smallest sum
            int sum=nums1[0]+nums2[0];
            pq.push({sum,{0,0}});

            // before move next chek visited
            set<pair<int,int>>visit;
            vector<vector<int>>ans;
            while(k!=0&&!pq.empty()){
                auto temp=pq.top();
                pq.pop();
                int i=temp.second.first;
                int j=temp.second.second;
                ans.push_back({nums1[i],nums2[j]});
                // chek j+1 out of bound and visited
                if(j+1<m&&!visit.count({i,j+1})){
                    int sum=nums1[i]+nums2[j+1];
                    pq.push({sum,{i,j+1}});
                    visit.insert({i,j+1});
                }
                // chek i+1 out of bound and visited
                if(i+1<n&&!visit.count({i+1,j})){
                    int sum=nums1[i+1]+nums2[j];
                    pq.push({sum,{i+1,j}});
                    visit.insert({i+1,j});
                }
                k--;
            }
       
return ans;
    }
};
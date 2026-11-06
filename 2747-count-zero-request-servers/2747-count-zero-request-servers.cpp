class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        vector<pair<int,int>>vp(m);
        for(int i=0;i<m;i++)vp[i]={logs[i][1],logs[i][0]};
        sort(vp.begin(),vp.end());
        int s=queries.size();
        vector<int>ans(s);
        vector<pair<int,int>>q(s);
        for(int i=0;i<s;i++)q[i]={queries[i],i};
        sort(q.begin(),q.end());
        unordered_map<int,int>mpp;
        int i=0,j=0;
        for(auto& it:q){
            int st=max(0,it.first-x),en=it.first,ind=it.second;
            while(j<m&&vp[j].first<=en){
                mpp[vp[j].second]++;
                j++;
            }
            while(i<m&&vp[i].first<st){
                if(mpp[vp[i].second]==1){
                    mpp.erase(vp[i].second);
                }
                else mpp[vp[i].second]--;
                i++;
            }
            ans[ind]=n-mpp.size();
        }
        return ans;
    }
};
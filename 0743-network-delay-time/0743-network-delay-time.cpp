class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>ti(n+1,INT_MAX);
        priority_queue<pair<int,int>>q;
        q.push({k,0});
        ti[k]=0;
        while(!q.empty()){
            auto [node,t]=q.top(); q.pop();
            for(auto it:adj[node]){
                int tim=t+it.second;
                if(tim<ti[it.first]){
                    ti[it.first]=tim;
                    q.push({it.first,tim});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,ti[i]);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
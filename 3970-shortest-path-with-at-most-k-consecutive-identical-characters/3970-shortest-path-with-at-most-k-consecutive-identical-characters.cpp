class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<long long int>>dist(n,vector<long long int>(k+1,LLONG_MAX));
        dist[0][k]=0;
        priority_queue<vector<long long int>,vector<vector<long long int>>,greater<vector<long long int>>>pq;
        pq.push({0,0,k});
        while(!pq.empty()){
            auto& it=pq.top();
            int d=it[0],u=it[1],rem=it[2];
            pq.pop();
            if(d>dist[u][rem])continue;
            for(auto& it:adj[u]){
                int v=it.first,w=it.second;
                if(labels[u]==labels[v]){
                    if(rem<=1)continue;
                    if(dist[v][rem-1]>d+w){
                        dist[v][rem-1]=d+w;
                        pq.push({d+w,v,rem-1});
                    }
                }
                else{
                    if(dist[v][k]>d+w){
                        dist[v][k]=d+w;
                        pq.push({d+w,v,k});
                    }
                }
            }
        }
        long long int ans=LLONG_MAX;
        for(int i=1;i<=k;i++)ans=min(ans,dist[n-1][i]);
        if(ans==LLONG_MAX)return -1;
        return ans;
    }
};
class Solution {
public:
void dfs(int node,int par,vector<vector<pair<int,int>>>&adj,vector<int>&ans){
    for(auto& [child,wt]:adj[node]){
        if(child!=par){
            ans[0]+=wt;
            dfs(child,node,adj,ans);
        }
    }
}
void dfs2(int node,int par,vector<vector<pair<int,int>>>&adj,vector<int>&ans){
    for(auto& [child,wt]:adj[node]){
        if(child!=par){
            ans[child]=ans[node];
            if(wt==0)ans[child]++;
            else ans[child]--;
            dfs2(child,node,adj,ans);
        }
    }
}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>ans(n,0);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1],0});
            adj[it[1]].push_back({it[0],1});
        }
        dfs(0,-1,adj,ans);
        dfs2(0,-1,adj,ans);
        return ans;
    }
};
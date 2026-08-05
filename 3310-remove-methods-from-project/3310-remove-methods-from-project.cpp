class Solution {
public:
void dfs(int k,vector<bool>&vis,vector<vector<int>>&adj){
    vis[k]=true;
    for(auto& it:adj[k]){
        if(!vis[it])dfs(it,vis,adj);
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto& it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>sus(n,false);
        vector<bool>vis(n,false);
        dfs(k,sus,adj);
        for(int i=0;i<n;i++){
            if(vis[i]||sus[i])continue;
            dfs(i,vis,adj);
        }
        vector<int>ans;
        bool pos=false;
        for(int i=0;i<n;i++){
            if(vis[i]&&sus[i]){
                pos=true;
                break;
            }
        }
        if(pos){
            for(int i=0;i<n;i++)ans.push_back(i);
        }
        else{
            for(int i=0;i<n;i++){
                if(!sus[i])ans.push_back(i);
            }
        }
        return ans;
    }
};
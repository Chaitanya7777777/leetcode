class Solution {
public:
unordered_map<int,set<int>>m;
void dfs(int node,int comp,vector<int>&vis,vector<vector<int>>&adj,vector<int>&compo){
    vis[node]=1;
    compo[node]=comp;
    m[comp].insert(node);
    for(auto& it:adj[node]){
        if(!vis[it])dfs(it,comp,vis,adj,compo);
    }
}
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>vis(c+1,0);
        vector<vector<int>>adj(c+1);
        for(auto& it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>compo(c+1);
        int comp=1;
        for(int i=1;i<=c;i++){
            if(!vis[i]){
                dfs(i,comp,vis,adj,compo);
                comp++;
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                int node=queries[i][1];
                int com=compo[node];
                if(m[com].count(node))ans.push_back(node);
                else if(m[com].size()!=0)ans.push_back(*(m[com].begin()));
                else ans.push_back(-1);
            }
            else{
                int node=queries[i][1];
                int com=compo[node];
                if(m[com].count(node))m[com].erase(node);
            }
        }
        return ans;
    }
};
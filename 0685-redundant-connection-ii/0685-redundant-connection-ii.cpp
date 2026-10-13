class Solution {
public:
int find(int u,vector<int>&par){
    if(u==par[u])return u;
    return par[u]=find(par[u],par);
}
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>par(n+1,0);
        vector<int>ca,cb;
        for(auto& it:edges){
            if(par[it[1]]==0)par[it[1]]=it[0];
            else{
                ca={par[it[1]],it[1]};
                cb=it;
                it[1]=0;
            }
        }
        for(int i=1;i<=n;i++)par[i]=i;
        for(auto& it:edges){
            if(it[1]==0)continue;
            int u=it[0],v=it[1],pu=find(u,par);
            if(pu==v){
                if(ca.empty())return it;
                return ca;
            }
            par[v]=pu;
        }
        return cb;
    }
};
class Solution {
public:
    vector<int>parent,size;
    int findUpar(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUpar(parent[u]);
    }
    void unionBySize(int u, int v) {
       int upu=findUpar(u);
       int upv=findUpar(v);
       if(upu==upv)return;
       if(size[upu]>size[upv]){
            parent[upv]=upu;
            size[upu]+=size[upv];
       }
       else{
            parent[upu]=upv;
            size[upv]+=size[upu];
       }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string it=accounts[i][j];
                if(m.find(it)==m.end())m[it]=i;
                else unionBySize(i,m[it]);
            }
        }
        vector<string>merged[n];
        for(auto it:m){
            merged[findUpar(it.second)].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i])temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};
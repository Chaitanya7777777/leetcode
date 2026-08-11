class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<set<int>>g(n);
        for(auto& it:edges){
            g[it[0]].insert(it[1]);
            g[it[1]].insert(it[0]);
        }
        queue<int>leaf;
        for(int i=0;i<n;i++){
            if(g[i].size()==1&&coins[i]==0)leaf.push(i);
        }
        int del=0,tot=edges.size()*2;
        while(!leaf.empty()){
            int x=leaf.front();
            leaf.pop();
            if(g[x].size()==0)continue;
            int p=*g[x].begin();
            g[p].erase(x);
            g[x].erase(p);
            del+=2;
            if(g[p].size()==1&&coins[p]==0)leaf.push(p);
        }
        for(int i=0;i<n;i++){
            if(g[i].size()==1)leaf.push(i);
        }
        int st=2;
        while(st--){
            int sz=leaf.size();
            while(sz--){
                int x=leaf.front();
                leaf.pop();
                if(g[x].size()==0)continue;
                int p=*g[x].begin();
                g[p].erase(x);
                g[x].erase(p);
                del+=2;
                if(g[p].size()==1)leaf.push(p);
            }
        }
        return tot-del;
    }
};
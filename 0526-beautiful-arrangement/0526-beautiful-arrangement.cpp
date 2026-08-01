class Solution {
public:
int cnt=0;
void solve(int n,int pos,vector<bool>&vis){
    if(pos>n){
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&(pos%i==0||i%pos==0)){
            vis[i]=true;
            solve(n,pos+1,vis);
            vis[i]=false;
        }
    }
}
    int countArrangement(int n) {
        vector<bool>vis(n+1,false);
        solve(n,1,vis);
        return cnt;
    }
};
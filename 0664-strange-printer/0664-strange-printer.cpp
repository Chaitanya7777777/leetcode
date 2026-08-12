class Solution {
public:
string removedupli(string& s){
    string res="";
    for(int i=0;i<s.size();i++){
        res+=s[i];
        int j=i;
        while(j<s.size()&&s[i]==s[j])j++;
        i=j-1;
    }
    return res;
}
int solve(int st,int en,string& s,vector<vector<int>>&dp){
    if(st>en)return 0;
    if(dp[st][en]!=-1)return dp[st][en];
    int mini=1+solve(st+1,en,s,dp);
    for(int k=st+1;k<=en;k++){
        if(s[st]==s[k]){
            mini=min(mini,solve(st,k-1,s,dp)+solve(k+1,en,s,dp));
        }
    }
    return dp[st][en]=mini;
}
    int strangePrinter(string s) {
        s=removedupli(s);
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp);
    }
};
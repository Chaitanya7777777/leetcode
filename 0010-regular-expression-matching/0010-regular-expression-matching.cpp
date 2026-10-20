class Solution {
public:
    bool ans(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(i<0&&j<0)return true;
        if(j<0)return false;
        if(i>=0&&dp[i][j]!=-1)return dp[i][j];
        if(i>=0&&(s[i]==p[j]||p[j]=='.'))return dp[i][j]=ans(s,p,i-1,j-1,dp);
        if(p[j]=='*'){
            if(i<0)return ans(s,p,i,j-2,dp);
            char ch=p[j-1];
            if(ch=='.'){
                return dp[i][j]=ans(s,p,i-1,j,dp)|ans(s,p,i,j-2,dp);
            }
            else{
                bool match=false;
                if(s[i]==ch)match=ans(s,p,i-1,j,dp);
                return dp[i][j]=match|ans(s,p,i,j-2,dp);
            }
        }
        if(i>=0)return dp[i][j]=false;
        return false;
         
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return ans(s,p,n-1,m-1,dp);
    }
};
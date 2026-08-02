class Solution {
public:
long long int mod=1e9+7;
    int countPalindromes(string s) {
        int n=s.size();
        if(n<5)return 0;
        vector<vector<int>>prepair(10,vector<int>(10,0)),sufpair(10,vector<int>(10,0));
        vector<int>pre(10,0),suf(10,0);
        for(int i=n-1;i>=0;i--){
            int c=s[i]-'0';
            for(int j=0;j<10;j++){
                sufpair[c][j]+=suf[j];
            }
            suf[c]++;
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            int c=s[i]-'0';
            suf[c]--;
            for(int j=0;j<10;j++)sufpair[c][j]-=suf[j];
            long long int ways=0;
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    ways=(ways+(1LL*prepair[j][k]*sufpair[k][j])%mod)%mod;
                }
            }
            ans=(ans+ways)%mod;
            for(int j=0;j<10;j++)prepair[j][c]+=pre[j];
            pre[c]++;
        }
        return ans;
    }
};
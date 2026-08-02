class Solution {
public:
long long int mod=1e9+7;
    int countPalindromes(string s) {
        int n=s.size();
        vector<vector<vector<int>>>pre(n,vector<vector<int>>(10,vector<int>(10,0)));
        vector<vector<vector<int>>>suf(n,vector<vector<int>>(10,vector<int>(10,0)));
        vector<int>cnt(10,0);
        for(int i=0;i<n;i++){
            int c=s[i]-'0';
            if(i>0){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        pre[i][j][k]=pre[i-1][j][k];
                        if(k==c)pre[i][j][k]+=cnt[j];
                    }
                }
            }
            cnt[c]++;
        }
        for(int i=0;i<10;i++)cnt[i]=0;
        for(int i=n-1;i>=0;i--){
            int c=s[i]-'0';
            if(i<n-1){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        suf[i][j][k]=suf[i+1][j][k];
                        if(k==c)suf[i][j][k]+=cnt[j];
                    }
                }
            }
            cnt[c]++;
        }
        long long int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    ans=(ans+1LL*pre[i-1][j][k]*suf[i+1][j][k])%mod;
                }
            }
        }
        return ans;
    }
};
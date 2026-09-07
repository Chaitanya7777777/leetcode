class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        int mod=1e9+7;
        vector<int>cntend(26,0);
        int sum=0;
        for(int i=0;i<n;i++){
            int id=s[i]-'a';
            int cur=(1+sum-cntend[id]+mod)%mod;
            sum=(sum+cur)%mod;
            cntend[id]=(cntend[id]+cur)%mod;
        }
        return sum;
    }
};
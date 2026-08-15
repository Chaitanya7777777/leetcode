class Solution {
public:
    int minOperations(string s) {
        int ans=INT_MAX;
        int n=s.size();
        for(int rot=0;rot<n;rot++){
            int ope=rot;
            for(int i=0;i<n/2;i++){
                int l=(i+rot)%n;
                int r=(n-i-1+rot)%n;
                int a=s[l]-'a',b=s[r]-'a';
                int dif=abs(a-b);
                ope+=min(dif,26-dif);
            }
            ans=min(ans,ope);
        }
        return ans;
    }
};
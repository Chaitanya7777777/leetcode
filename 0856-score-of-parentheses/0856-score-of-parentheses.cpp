class Solution {
public:
int solve(int l,int r,string& s){
    if(l>=r)return 1;
    int res=0;
    while(l<=r){
        int nr=l+1,d=1;
        while(nr<=r){
            if(s[nr]==')')d--;
            else d++;
            if(d==0)break;
            nr++;
        }
        res+=solve(l+1,nr-1,s);
        l=nr+1;
    }
    return 2*res;
}
    int scoreOfParentheses(string s) {
        int ans=0;
        int n=s.size();
        int i=0;
        while(i<n){
            int r=i+1,d=1;
            while(r<n){
                if(s[r]==')')d--;
                else d++;
                if(d==0)break;
                r++;
            }
            ans+=solve(i+1,r-1,s);
            i=r+1;
        }
        return ans;
    }
};
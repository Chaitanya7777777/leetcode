class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int d=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')d++;
            else{
                if(d==0){
                    int depth=0;
                    while(i<n&&s[i]==')'){
                        depth++;
                        i++;
                    }
                    ans+=depth/2;
                    if(depth&1)ans+=2;
                    i--;
                    continue;
                }
                if(i<n-1){
                    d--;
                    if(s[i+1]==')'){
                        i++;
                    }
                    else ans++;
                }
                else{
                    ans++;
                    d--;
                }
            }
        }
        ans+=2*d;
        return ans;
    }
};
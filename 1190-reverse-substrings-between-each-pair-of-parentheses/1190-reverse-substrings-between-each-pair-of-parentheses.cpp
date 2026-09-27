class Solution {
public:
string solve(int l,int r,string& s){
    string res="";
    for(int i=l;i<=r;i++){
        if(s[i]!='(')res+=s[i];
        else{
            int j=i+1;
            int cnt=1;
            while(j<=r){
                if(s[j]=='(')cnt++;
                else if(s[j]==')')cnt--;
                if(cnt==0)break;
                j++;
            }
            string mid=solve(i+1,j-1,s);
            res+=mid;
            i=j;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
    string reverseParentheses(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='(')ans+=s[i];
            else{
                int j=i+1;
                int cnt=1;
                while(j<n){
                    if(s[j]=='(')cnt++;
                    else if(s[j]==')')cnt--;
                    if(cnt==0)break;
                    j++;
                }
                string mid=solve(i+1,j-1,s);
                ans+=mid;
                i=j;
            }
        }
        return ans;
    }
};
class Solution {
public:
unordered_map<int,set<string>>m;
void solve(string& res,int i,int n,int o,int d,string& s){
    if(i==n){
        if(d==0){
            m[o].insert(res);
        }
        return;
    }
    solve(res,i+1,n,o+1,d,s);
    int di=0;
    if(s[i]==')')di=-1;
    else if(s[i]=='(')di=1;
    if(d+di>=0){
        res+=s[i];
        solve(res,i+1,n,o,d+di,s);
        res.pop_back();
    }
}
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        string res="";
        solve(res,0,n,0,0,s);
        int mini=100;
        for(auto& it:m)mini=min(mini,it.first);
        vector<string>ans(m[mini].begin(),m[mini].end());
        return ans;
    }
};
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        for(auto& it:knowledge){
            m[it[0]]=it[1];
        }
        string ans="";
        int i=0,n=s.size();
        while(i<n){
            if(s[i]=='('){
                i++;
                string x="";
                while(s[i]!=')'){
                    x+=s[i];
                    i++;
                }
                if(m.find(x)!=m.end())ans+=m[x];
                else ans+='?';
                i++;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};
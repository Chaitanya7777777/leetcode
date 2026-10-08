class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int level=0;
        string result="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(level>0)result+=s[i];
                level++;
            }
            else if(s[i]==')'){
                if(level>1)result+=s[i];
                level--;
            }
        }
        return result;
    }
};
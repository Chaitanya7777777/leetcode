class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int c=0,mc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')c++;
            else if(s[i]==')')c--;
            mc=max(mc,c);
        }
        return mc;
    }
};
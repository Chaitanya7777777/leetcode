class Solution {
public:
    int minOperations(string s) {
        string t=s;
        sort(t.begin(),t.end());
        if(s==t)return 0;
        if(s.size()==2)return -1;
        int n=s.size();
        if(s[0]==t[0]||s[n-1]==t[n-1])return 1;
        for(int i=1;i<n-1;i++){
            if(s[i]==t[0]||s[i]==t[n-1])return 2;
        }
        return 3;
    }
};
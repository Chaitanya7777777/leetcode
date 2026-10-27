class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m);
        string res(n,'.');
        ans[0]=res;
        for(int i=0;i<n-1;i++)res[i]='#';
        for(int i=1;i<m;i++)ans[i]=res;
        return ans;
    }
};
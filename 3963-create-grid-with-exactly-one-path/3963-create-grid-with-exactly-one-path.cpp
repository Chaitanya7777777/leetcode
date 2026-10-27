class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string res(n,'.');
        ans.push_back(res);
        for(int i=0;i<n-1;i++)res[i]='#';
        for(int i=1;i<m;i++)ans.push_back(res);
        return ans;
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++)v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        vector<vector<int>>a,b;
        vector<int>a0,b0;
        a0.push_back(v[0].first);
        b0.push_back(v[0].second);
        for(int i=1;i<n;i++){
            if(v[i].first-v[i-1].first<=limit){
                a0.push_back(v[i].first);
                b0.push_back(v[i].second);
            }
            else{
                a.push_back(a0);
                b.push_back(b0);
                a0.clear();
                b0.clear();
                a0.push_back(v[i].first);
                b0.push_back(v[i].second);
            }
        }
        a.push_back(a0);
        b.push_back(b0);
        int comp=a.size();
        for(int i=0;i<comp;i++){
            sort(a[i].begin(),a[i].end());
            sort(b[i].begin(),b[i].end());
        }
        vector<int>ans(n);
        for(int i=0;i<comp;i++){
            for(int j=0;j<a[i].size();j++){
                ans[b[i][j]]=a[i][j];
            }
        }
        return ans;
    }
};
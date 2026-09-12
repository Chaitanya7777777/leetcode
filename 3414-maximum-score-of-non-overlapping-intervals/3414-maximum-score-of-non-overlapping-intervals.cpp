class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>a;
        for(int i=0;i<n;i++){
            a.push_back({intervals[i][1],intervals[i][0],intervals[i][2],i});
        }
        sort(a.begin(),a.end());
        vector<vector<long long>>dp(n+1,vector<long long>(5,0));
        vector<vector<vector<int>>>indices(n+1,vector<vector<int>>(5));
        for(int i=1;i<=n;i++){
            int left=a[i-1][1];
            int wt=a[i-1][2];
            int orid=a[i-1][3];
            int p=0,low=0,high=i-2;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(a[mid][0]<left){
                    p=mid+1;
                    low=mid+1;
                }
                else high=mid-1;
            }
            for(int j=1;j<=4;j++){
                dp[i][j]=dp[i-1][j];
                indices[i][j]=indices[i-1][j];
                long long takescore=dp[p][j-1]+wt;
                vector<int>takeindices=indices[p][j-1];
                takeindices.push_back(orid);
                sort(takeindices.begin(),takeindices.end());
                if(takescore>dp[i][j]||(takescore==dp[i][j]&&takeindices<indices[i][j])){
                    dp[i][j]=takescore;
                    indices[i][j]=takeindices;
                }
            }
        }
        return indices[n][4];
    }
};
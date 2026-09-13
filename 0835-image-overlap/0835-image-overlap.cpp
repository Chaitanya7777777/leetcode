class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1)a.push_back({i,j});
                if(img2[i][j]==1)b.push_back({i,j});
            }
        }
        vector<vector<int>>cnt(2*n,vector<int>(2*n,0));
        int ans=0;
        for(auto& i:a){
            for(auto& j:b){
                int dx=i.first-j.first+n,dy=i.second-j.second+n;
                cnt[dx][dy]++;
                ans=max(ans,cnt[dx][dy]);
            }
        }
        return ans;
    }
};
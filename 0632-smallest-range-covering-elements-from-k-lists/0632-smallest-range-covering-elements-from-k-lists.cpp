class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int x:nums[i])v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        unordered_map<int,int>m;
        int l=0,ans=INT_MAX,start=-1;
        for(int i=0;i<v.size();i++){
            m[v[i].second]++;
            while(m.size()==n){
                if(ans>v[i].first-v[l].first){
                    ans=v[i].first-v[l].first;
                    start=v[l].first;
                }
                m[v[l].second]--;
                if(m[v[l].second]==0)m.erase(v[l].second);
                l++;
            }
        }
        return {start,start+ans};
    }
};
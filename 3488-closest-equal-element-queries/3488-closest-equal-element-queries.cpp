class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        vector<int>q(n,INT_MAX);
        unordered_map<int,int>m;
        for(int i=0;i<2*n;i++){
            if(m.find(nums[i%n])==m.end()){
                m[nums[i%n]]=i;
                continue;
            }
            q[i%n]=min(q[i%n],i-m[nums[i%n]]);
            m[nums[i%n]]=i;
        }
        m.clear();
        for(int i=2*n-1;i>=0;i--){
            if(m.find(nums[i%n])==m.end()){
                m[nums[i%n]]=i;
                continue;
            }
            q[i%n]=min(q[i%n],m[nums[i%n]]-i);
            m[nums[i%n]]=i;
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            if(q[queries[i]]>=n)ans[i]=-1;
            else ans[i]=q[queries[i]];
        }
        return ans;
    }
};
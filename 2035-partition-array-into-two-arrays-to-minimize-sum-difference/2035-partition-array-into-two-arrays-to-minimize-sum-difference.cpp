class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size(),sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        int N=n/2;
        vector<vector<int>>l(N+1),r(N+1);
        for(int mask=0;mask<(1<<N);mask++){
            int idx=0,ls=0,rs=0;
            for(int i=0;i<N;i++){
                if(mask&(1<<i)){
                    idx++;
                    ls+=nums[i];
                    rs+=nums[i+N];
                }
            }
            l[idx].push_back(ls);
            r[idx].push_back(rs);
        }
        for(int idx=0;idx<=N;idx++){
            sort(r[idx].begin(),r[idx].end());
        }
        int res=min(abs(sum-2*l[N][0]),abs(sum-2*r[N][0]));
        for(int idx=1;idx<N;idx++){
            for(auto& a:l[idx]){
                int b=(sum-2*a)/2;
                int ridx=N-idx;
                auto& v=r[ridx];
                auto itr=lower_bound(v.begin(),v.end(),b);
                if(itr!=v.end())res=min(res,abs(sum-2*(a+(*itr))));
            }
        }
        return res;
    }
};
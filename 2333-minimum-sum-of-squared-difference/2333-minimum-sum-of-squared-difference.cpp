class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int mind=INT_MAX,maxd=0;
        long long int k=k1+k2;
        for(int i=0;i<n;i++){
            mind=min(mind,abs(nums1[i]-nums2[i]));
            maxd=max(maxd,abs(nums1[i]-nums2[i]));
        }
        int l=0,r=maxd;
        int reqd=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            bool ok=true;
            long long int ope=0;
            for(int i=0;i<n;i++){
                int x=abs(nums1[i]-nums2[i]);
                if(x<=mid)continue;
                ope+=x-mid;
                if(ope>k){
                    ok=false;
                    break;
                }
            }
            if(ok){
                reqd=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        long long int remo=k;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            int x=abs(nums1[i]-nums2[i]);
            if(x>reqd){
                remo-=(x-reqd);
                pq.push(reqd);
            }
            else pq.push(x);
        }
        long long int ans=0;
        while(!pq.empty()){
            long long int x=pq.top(); pq.pop();
            if(x==0)break;
            if(remo){
                x--;
                remo--;
            }
            ans+=x*x;
        }
        return ans;
    }
};
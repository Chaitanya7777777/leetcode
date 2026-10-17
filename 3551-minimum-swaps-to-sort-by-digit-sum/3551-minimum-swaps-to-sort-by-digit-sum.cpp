class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>digs(n),ind(n);
        for(int i=0;i<n;i++){
            long long int x=nums[i],s=0;
            while(x){
                s+=x%10;
                x/=10;
            }
            digs[i]=s;
            ind[i]=i;
        }
        sort(ind.begin(),ind.end(),[&](int a,int b){
            if(digs[a]!=digs[b])return digs[a]<digs[b];
            return nums[a]<nums[b];
        });
        vector<int>tarp(n);
        for(int i=0;i<n;i++){
            tarp[ind[i]]=i;
        }
        vector<bool>vis(n,false);
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                int j=i;
                while(!vis[j]){
                    vis[j]=true;
                    j=tarp[j];
                }
            }
        }
        return n-comp;
    }
};
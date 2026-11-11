class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long int ans=1LL*cost1*need1+1LL*cost2*need2;
        long long int diff=abs(need1-need2);
        long long int coste=0;
        if(need1>need2)coste=diff*cost1;
        else coste=diff*cost2;
        long long int mini=min(need1,need2);
        ans=min(ans,mini*costBoth+coste);
        ans=min(ans,1LL*costBoth*max(need1,need2));
        return ans;
    }
};
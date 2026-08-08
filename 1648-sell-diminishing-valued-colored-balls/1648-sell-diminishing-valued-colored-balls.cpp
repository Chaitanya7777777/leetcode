class Solution {
public:
long long int mod=1e9+7;
    int maxProfit(vector<int>& inv, int orders) {
        long long int ans=0,dist=1;
        sort(inv.begin(),inv.end());
        int n=inv.size();
        for(int i=n-1;i>=0&&orders>0;i--,dist++){
            long long int cur=inv[i],prev=0;
            if(i>0)prev=inv[i-1];
            long long int turn=min(orders/dist,cur-prev);
            orders-=turn*dist;
            ans=(ans+(cur*(cur+1)-(cur-turn)*(cur-turn+1))/2*dist)%mod;
            if(cur-prev>turn){
                ans=(ans+orders*(cur-turn))%mod;
                break;
            }
        }
        return ans;
    }
};
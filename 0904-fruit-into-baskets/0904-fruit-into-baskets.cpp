class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int n=fruits.size();
        int ans=0;
        int l=0,dist=0;
        for(int i=0;i<n;i++){
            m[fruits[i]]++;
            if(m[fruits[i]]==1)dist++;
            while(dist>2){
                if(m[fruits[l]]==1)dist--;
                m[fruits[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
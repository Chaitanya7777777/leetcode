class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>ap;
        for(int x:arr1){
            while(!ap.count(x)&&x>0){
                ap.insert(x);
                x=x/10;
            }
        }
        int ans=0;
        for(int x:arr2){
            while(!ap.count(x)&&x>0){
                x=x/10;
            }
            if(x>0){
                ans=max(ans,(int)(log10(x))+1);
            }
        }
        return ans;
    }
};
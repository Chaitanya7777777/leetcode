class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int totski=skill[0]+skill[n-1];
        long long chem=1LL*skill[0]*skill[n-1];
        int i=1,j=n-2;
        while(i<j){
            if(totski!=(skill[i]+skill[j]))return -1;
            chem+=1LL*skill[i]*skill[j];
            i++;
            j--;
        }
        return chem;
    }
};
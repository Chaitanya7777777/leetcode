class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        for(int x:arr1){
            bool pos=true;
            for(int y:arr2){
                if(abs(x-y)<=d){
                    pos=false;
                    break;
                }
            }
            if(pos)cnt++;
        }
        return cnt;
    }
};
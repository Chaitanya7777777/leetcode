class Solution {
public:
    int minFlips(string target) {
        int flip=0,cnt=0;
        for(char c:target){
            if(flip){
                if(c=='0'){
                    flip=0;
                    cnt++;
                }
            }
            else{
                if(c=='1'){
                    flip=1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
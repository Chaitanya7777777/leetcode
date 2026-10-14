class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(sum>0&&num>0){
            char x;
            if(sum>=9){
                x='9';
                sum-=9;
            }
            else{
                x=sum+'0';
                sum=0;
            }
            ans+=x;
            num--;
        }
        while(num>0){
            ans+='0';
            num--;
        }
        if(sum>0)return "";
        return ans;
    }
};
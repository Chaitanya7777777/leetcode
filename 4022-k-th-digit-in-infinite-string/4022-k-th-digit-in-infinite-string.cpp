class Solution {
public:
    int kthDigit(long long k) {
        if(k<=9)return k;
        k-=9;
        for(int d=1;;d++){
            long long int st=1;
            for(int i=1;i<d;i++)st=st*10;
            long long int en=st*10-1;
            long long int bl=en-st+1;
            long long int bllen=1LL*10*(d+1);
            long long int grplen=bl*bllen;
            if(k>grplen){
                k-=grplen;
                continue;
            }
            long long int b=st+(k-1)/bllen;
            long long int pos=(k-1)%bllen;
            long long int id=pos/(d+1);
            long long int dig=pos%(d+1);
            if(b%2==0){
                long long int num=10*b+id;
                string s=to_string(num);
                return s[dig]-'0';
            }
            else{
                long long int num=10*b+(9-id);
                string s=to_string(num);
                return s[dig]-'0';
            }
        }
        return 0;
    }
};
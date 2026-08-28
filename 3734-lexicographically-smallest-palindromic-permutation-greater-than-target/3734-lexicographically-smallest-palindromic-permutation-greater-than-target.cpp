class Solution {
public:
    string makePalindrome(string& left,string& middle){
        string right=left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
    string lexPalindromicPermutation(string s,string target){
        int n=s.size();
        if(n==1){
            return (s>target)?s:"";
        }
        vector<int>count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        string middle="";
        for(int i=0;i<26;i++){
            if(count[i]%2==1){
                if(!middle.empty()){
                    return "";
                }
                middle=char('a'+i);
            }
            count[i]/= 2;
        }
        string left= "";
        for(int pos=0;pos<n/2;pos++){
            bool found=false;
            for(int c=0;c<26;c++){
                if(count[c]==0){
                    continue;
                }
                count[c]--;
                string candidate=left+char('a'+c);
                string largestLeft=candidate;
                for(int x=25;x>=0;x--){
                    largestLeft+=string(count[x],char('a'+x));
                }
                string largestPalindrome=makePalindrome(largestLeft,middle);
                if(largestPalindrome>target){
                    left=candidate;
                    found=true;
                    break;
                }
                count[c]++;
            }
            if(!found){
                return "";
            }
            if(left[pos]>target[pos]) {
                string finalLeft=left;
                for(int c=0;c<26;c++){
                    finalLeft+=string(count[c],char('a'+c));
                }
                return makePalindrome(finalLeft,middle);
            }
        }
        return makePalindrome(left,middle);
    }
};
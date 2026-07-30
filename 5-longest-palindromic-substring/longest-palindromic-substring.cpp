class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int left;
        int right;
        int curlen;
        int start=0;
        int maxlen=1;
        for(int i=0;i<s.length();i++){

            
                left=i;
                right=i+1;

                while(left>=0&&right<n&&s[left]==s[right]){
                        
                        curlen=right-left+1;
                        if(curlen>maxlen){
                            maxlen=curlen;
                            start=left;
                        }

                    left--;
                    right++;
                }

            
             
                 left=i;
                right=i;

                while(left>=0&&right<n&&s[left]==s[right]){
                        curlen=right-left+1;
                        if(curlen>maxlen){
                            maxlen=curlen;
                            start=left;
                        }

                    left--;
                    right++;

                 }

            }
        
        string ans;
        for(int i=start;i<start+maxlen;i++){

            ans+=s[i];
        }
        return ans;
    }
};
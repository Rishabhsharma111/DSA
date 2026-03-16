class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int first=0,secound=0,len=0;
         
         while(secound<s.size()){
            while(count[s[secound]]){
                count[s[first]]=0;
                first++;
            }
            count[s[secound]]=1;
            len=max(len,secound-first+1);
            secound++;

         }
         return len;
    }
};
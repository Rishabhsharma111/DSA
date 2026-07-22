class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int>mp;

        int l=0;
        int r=0;
        int len=0;

        while(r<s.size()){

            
                while(mp[s[r]]>0){
                    mp[s[l]]--;
                      l++;
                  
                    
                }
                if(mp[s[r]]==0)
                    mp[s[r]]++;

            
           
              
              len=max(len,r-l+1);
              r++;
          
        }
        return len;
         
    }
};
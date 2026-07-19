class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

          unordered_map<char,int>mp;

          for(char ch:ransomNote){
            mp[ch]++;
          }  
          for(char ch:magazine){
            mp[ch]--;
          }

          for(auto it:mp){
            if(it.second>0)
                return false;
            
          }

        return true;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char,int>mp;

        for(char ch:t){
            mp[ch]++;
        }

        
        for(char ch:s){
            mp[ch]--;
        }
        char ans;
        for(auto it:mp){
            if(it.second!=0){
                 ans=it.first;
            }
        }
        return ans;
    }
};
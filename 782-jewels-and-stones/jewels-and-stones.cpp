class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char,int>mp;

        for(char ch:stones){
            mp[ch]++;
        }
        int result =0;
        for(int i=0;i<jewels.size();i++)
        {
            for(auto it:mp){
                if(it.first==jewels[i]){
                    result+=it.second;
                }
            }
        }

        return result;
        
    }
};
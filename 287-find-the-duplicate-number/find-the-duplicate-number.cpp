class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>mp;  //using hashing
         int resu;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

        }
      for(auto it:mp){
        if(it.second>=2){
           resu=it.first;
          
        }
        else 
        continue;
      }
        return resu;
    }
};
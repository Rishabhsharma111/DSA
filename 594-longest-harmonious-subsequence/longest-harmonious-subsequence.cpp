class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;      //calculate frequency 
        }
        int maxi=0;
        for(auto it:mp){
           if(mp.count(it.first + 1)){  //check if (it.first+1) exist or not 
            maxi=max(maxi,it.second+mp[it.first+1]);
           }
        }
        return maxi;
    }
};
class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi=0;
        for(auto it:mp){
           if(mp.count(it.first + 1)){
            maxi=max(maxi,it.second+mp[it.first+1]);
           }
        }
        return maxi;
    }
};
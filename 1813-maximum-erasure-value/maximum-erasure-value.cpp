class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int,int>mp;

        int l=0;int r=0;
        int temp=0;
        int sum=0;
        int maxi=INT_MIN;
        while(r<nums.size()){

            if(mp.count(nums[r])){ //count is used to find in map
                temp=mp[nums[r]];
                mp[nums[r]]=r;

                while(l<=temp){
                    sum-=nums[l];

                    l++;
                }
            }
            else {
            
            mp[nums[r]]=r;
            }
            sum+=nums[r];
           
             maxi=max(sum,maxi);
             r++;
        }
        return maxi;
    }
};
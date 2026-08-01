class Solution {
public://prefixsum
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        freq[0]=-1; //initialize freq with(0,-1)
        int remainder=0;
        int  prefixsum=0;
        int total=0;
        for(int i=0;i<nums.size();i++){

            prefixsum+=nums[i];
            remainder=prefixsum%k;
            if(freq.count(remainder)){
                if(i - freq[remainder]>=2){
                    return true;
                }
            }if(!freq.count(remainder))
            freq[remainder]=i;
        }
        return false;

    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxsize=INT_MIN;
        int i=0,j=0;
        int count =0;
        while(j<nums.size()){

            if(nums[j]==0){
                count++;
            }

            while(count>1){
                if(nums[i]==0){
                    count--;
                }
                i++;
            }

            maxsize=max(maxsize,j-i);
            j++;
        }

        return maxsize;
        
    }
};
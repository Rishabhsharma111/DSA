class Solution {
public:

bool issorted(vector<int>&nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]){
            return false;

        }
        
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int count =0;
        while(!issorted(nums)){

            int minisum=nums[0]+nums[1];
            int index=0;

            for(int i=1;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];

                if(sum<minisum){
                    minisum=sum;
                    index=i;
                }

            }
            nums[index]=minisum;

            nums.erase(nums.begin()+index+1);

            count++;
        }
        return count;

    }
};
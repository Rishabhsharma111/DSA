class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>answer(nums.size());

        int prefixproduct=1;
        int ans=0;

       for(int i=0;i<nums.size();i++){

        answer[i]=prefixproduct;
        prefixproduct=prefixproduct*nums[i];
        
       }
       int sufixproduct=1;
       for(int i=nums.size()-1;i>=0;i--){

        answer[i]*=sufixproduct;
        sufixproduct=sufixproduct*nums[i];
        
       }
       return answer;

    }
};
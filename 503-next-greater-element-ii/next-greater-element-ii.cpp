class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int>st;

        vector<int>ans(nums.size(),-1);
        int index=0;
        int n=nums.size();
        for(int i=0;i<2*nums.size();i++){

            while(!st.empty()&&nums[st.top()]<nums[i%n]){
             
                ans[st.top()]=nums[i%n];
                st.pop();
            }
            if(i<n)
            st.push(i%n);
        }

      
        
        return ans;
        
    }
};
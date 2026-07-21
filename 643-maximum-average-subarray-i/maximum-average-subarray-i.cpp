class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {


        

        int l=0;
        int r=k;
            double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxi=sum;

        while(r<nums.size()){
            
           maxi=max(maxi,sum);
             sum+=nums[r];
            sum-=nums[l];
              maxi=max(maxi,sum);
            l++;
            r++;
           
        }
            double avg;
            avg=maxi/k;

        

        return avg;

        
    }
};
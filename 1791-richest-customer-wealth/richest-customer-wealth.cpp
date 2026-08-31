class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

       
        int maxi=INT_MIN;
        int n=accounts.size();
        int m=accounts[0].size();

        for(int i=0;i<n;i++){
             int sum=0;
            for(int j=0;j<m;j++){
                sum+=accounts[i][j];

               
                }
                 if(sum>maxi){
                    maxi=sum;
            }
        }
        return maxi;
        
    }
};
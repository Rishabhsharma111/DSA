class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for(int i = 0; i < accounts.size(); i++){   //traverese each row
            int sum = 0;

            for(int j = 0; j < accounts[i].size(); j++){
                sum += accounts[i][j];   // sum of current customer
            }

            maxWealth = max(maxWealth, sum);  // update maximum wealth
        }

        return maxWealth;
    }
};
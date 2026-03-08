class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[j][i] = matrix[i][j];    //not just swaping bcz here are rect matrix in test cases
            }
        }

        return ans;
    }
};
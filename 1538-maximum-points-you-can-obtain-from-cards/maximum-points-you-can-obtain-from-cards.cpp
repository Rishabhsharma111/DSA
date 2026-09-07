class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        vector<int> prefixsum(n);

        prefixsum[0] = cardPoints[0];

        for(int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + cardPoints[i];
        }

        int ans = 0;

        for(int left = 0; left <= k; left++) {

            int right = k - left;

            int leftSum = 0;
            int rightSum = 0;

            // left cards
            if(left > 0) {
                leftSum = prefixsum[left - 1];
            }

            // right cards
            if(right > 0) {
                if(right == n) {
                    rightSum = prefixsum[n - 1];
                }
                else {
                    rightSum = prefixsum[n - 1] - prefixsum[n - right - 1];
                }
            }

            ans = max(ans, leftSum + rightSum);
        }

        return ans;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] < minK || nums[end] > maxK) {
                start = end + 1;
            }

            total += end - start + 1;
        }

        return total;
    }
};
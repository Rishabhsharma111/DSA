class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> resultsubset;
        resultsubset.push_back({});

        for (int i = 0; i < nums.size(); i++) {

            int n = resultsubset.size();

            for (int j = 0; j < n; j++) {

                vector<int> ans = resultsubset[j];

                ans.push_back(nums[i]);

                resultsubset.push_back(ans);
            }
        }

        set<vector<int>> s(resultsubset.begin(), resultsubset.end());

        return vector<vector<int>>(s.begin(), s.end());
    }
};
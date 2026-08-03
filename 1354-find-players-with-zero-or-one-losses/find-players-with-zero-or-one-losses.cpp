class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        vector<int>ans1;
        vector<int>ans2;
         vector<vector<int>>result;

       for (int i = 0; i < matches.size(); i++) {
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
        for(auto it:mp1){
            if(mp2.count(it.first)){
                continue;
            }
            else{
                ans1.push_back(it.first);
            }
        }
        for(auto it:mp2){
            if(it.second==1){
                ans2.push_back(it.first);
            }
        }
        sort(ans1.begin(),ans1.end());
        sort(ans2.begin(),ans2.end());

            result.push_back(ans1);
            result.push_back(ans2);

            return result;
        
    }
};
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mp;

        for(char ch : s)
        {
            mp[ch]++;
        }

        vector<pair<int,char>> v;

        for(auto it : mp)
        {
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());

        string result;

        for(auto it : v)
        {
            while(it.first)
            {
                result += it.second;
                it.first--;
            }
        }

        return result;
    }
};
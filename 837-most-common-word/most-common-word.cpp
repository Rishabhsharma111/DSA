class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
            char ch;
        for(int i=0;i<paragraph.size();i++){
        paragraph[i] = tolower(paragraph[i]);

            if(!isalpha(paragraph[i])){
                paragraph[i] =' ';

            }

        }

        stringstream ss(paragraph);

        string  word;
        unordered_map<string, int>mp;

        while(ss>>word){

            mp[word]++;
        }
        int maxi=INT_MIN;
        string ans;
                for(auto it : mp)
        {
            bool bannedWord = false;

            for(string x : banned)
            {
                if(it.first == x)
                {
                    bannedWord = true;
                    break;
                }
            }

            if(!bannedWord && it.second > maxi)
            {
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};
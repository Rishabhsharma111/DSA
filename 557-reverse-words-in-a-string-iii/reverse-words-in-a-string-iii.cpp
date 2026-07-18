class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);

        string word;
            string ans;
        while(ss>>word){

            for(int i =word.size()-1;i>=0;i--)
            {

               ans += word[i];  //ans=ans+word[i] shows time issue
            }
                ans+=" ";
        }

        int end=ans.size()-1;
        if(!ans.empty()&&ans[end]==' '){  // to remove last space coming in ans
            ans.erase(end);
        }
        return ans;
    }
};
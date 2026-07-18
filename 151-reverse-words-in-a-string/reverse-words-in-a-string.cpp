class Solution {
public:
    string reverseWords(string s) {

        stack<string>words;

        stringstream ss(s);

        string word;
           
        while(ss>>word){

            words.push(word);
           
        }
        string ans;
        while(!words.empty()){

            ans=ans+words.top();
            
            words.pop();
             if (!words.empty())
             ans += " ";

        }

        return ans;
        
    }
};
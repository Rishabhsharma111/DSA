class Solution {
public:
    string removeDuplicateLetters(string s) {

        unordered_map<char,int>mp;

        stack<char>st;

        unordered_map<char,bool>vis;

        for(int i=0;i<s.size();i++){
            
            mp[s[i]]=i;
        }

        for(int i=0;i<s.size();i++){

            char ch=s[i];

            if(vis[ch])
            continue;

            while(!st.empty()&&st.top()>ch&&mp[st.top()]>i){

                char topchar=st.top();
                st.pop();
                vis[topchar]=false;

                
            }

            st.push(ch);
            vis[ch]=true;
        }
        string ans;
        while(!st.empty()){

            ans+=st.top();
            st.pop();


        }
            reverse(ans.begin(),ans.end());

            return ans;

    }
};
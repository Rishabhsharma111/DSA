class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int>st;
        int count=0;
        string ans;
        string result;

        for(int i=0;i<num.size();i++){
            while(!st.empty()&&num[st.top()]>num[i]&&count<k){

                count++;
                 st.pop();
               
                
            }
            st.push(i);
        }
        while (count < k) {
            st.pop();
            count++;
        }
                while(!st.empty()){
            ans+=num[st.top()];
            st.pop();

        }

        reverse(ans.begin(),ans.end());

       int i=0;
       while(i<ans.size()&&ans[i]=='0'){
        i++;

       }

       if(i==ans.size()){
        ans="0";
       }
      else
      {
        ans=ans.substr(i);
      }

      return ans;

      
    }
};
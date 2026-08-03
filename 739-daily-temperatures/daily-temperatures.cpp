class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

       stack<pair<int,int>> st;

        vector<int>ans(temperatures.size(),0);
        int count=0;

        for(int i=0;i<temperatures.size();i++){


            while(!st.empty()&&st.top().first<temperatures[i]){

                count=i-(st.top().second);
                ans[st.top().second]=count;
                st.pop();
            }
            

            st.push({temperatures[i],i});


        }
        


        return ans;
    }
};
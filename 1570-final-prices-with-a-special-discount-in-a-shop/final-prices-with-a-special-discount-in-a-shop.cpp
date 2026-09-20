class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<pair<int,int>>st;
        vector<int>ans(prices.size());

        for(int i=0;i<prices.size();i++){

            int dis=0;

            if(st.empty()){
                st.push({prices[i],i});
            }
            while(!st.empty()&&st.top().first>=prices[i]){

                dis=st.top().first-prices[i];
                ans[st.top().second]=dis;
                st.pop();
                

            }
            st.push({prices[i],i});

            
        }


        while(!st.empty()){

            ans[st.top().second]=st.top().first;
            st.pop();

        }

        return ans;
        
    }
};
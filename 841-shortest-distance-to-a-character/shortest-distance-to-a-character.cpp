class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        vector<int>ans;

        for(int i=0;i<s.size();i++){

            if(s[i]==c){
                ans.push_back(i);
            }
        }

        vector<int>answer;

        for(int i=0;i<s.size();i++){

            int mini=INT_MAX;

            for(int j=0;j<ans.size();j++){

            
                int dis =abs(i-ans[j]);

                mini=min(mini,dis);
            }
            answer.push_back(mini);
        }

        

        return answer;
        
    }
};
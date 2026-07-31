class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        vector<int>ans;
        int n=arr.size();
        int l=0;
        for(int i=0;i<arr.size();i++){

               
                  if(arr[i]==0){
                            
                 if (l < n) {
                ans.push_back(0);
                l++;
            }

            if (l < n) {
                ans.push_back(0);
                l++;
            }
                  }
                  else
                  {
                    if (l<n){
                     ans.push_back(arr[i]);
                        l++;
                  }
                  }
                
        }
                
        arr=ans;
    }
};
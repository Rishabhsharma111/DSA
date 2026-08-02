class Solution {
public:
    int totalFruit(vector<int>& fruits) {

         unordered_map<int,int>mp;

         int l=0;int r=0;
        int count=0;
        int maxi=INT_MIN;
         while(r<fruits.size()){
            
                mp[fruits[r]]++;
              
            
            
                while(mp.size()>2){
                    mp[fruits[l]]--;
        
                if(mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                    
                    l++;
                
               
            }
             count=r-l+1;
            maxi=max(count,maxi);

            r++;
            
         }
         return maxi;
        
    }
};
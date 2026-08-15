class Solution {
public:
    bool checkRecord(string s) {

        unordered_map<int,int>mp;
        int countl=0;
        for(char ch:s){
           if(ch=='A'){
           mp['A']++;}

           if(ch=='L'){
            countl++;

            if(countl>=3)
                return false;
            
           }
           else
           {
            countl=0;
           }
        }
        return mp['A']<2;
        
    }
};